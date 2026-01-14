"""
Lazy Segment Tree (Lazy Propagation Segment Tree)

A highly flexible segment tree implementation that supports:
- Range updates with lazy propagation
- Range queries
- Point updates and queries
- Binary search on the segment tree

Time Complexity:
- Build: O(n)
- Query: O(log n)
- Update: O(log n)
- Point operations: O(log n)

Space Complexity: O(n)

Key Concepts:
1. Lazy Propagation: Delay updates until necessary, storing them in lazy tags
2. Generic Operations: Supports any associative operation via function parameters
3. Binary Indexed Structure: Uses a complete binary tree stored in an array

Parameters:
- nums: Initial array values
- idval: Identity element for the query operation (e.g., 0 for sum, inf for min)
- idlazy: Identity element for lazy updates (e.g., 0 for addition)
- op: Binary operation for combining values (e.g., lambda x,y: x+y for range sum)
- apply: Function to apply lazy value to a node (e.g., lambda lazy, val: lazy + val)
- compose: Function to combine two lazy values (e.g., lambda new, old: new + old)
"""

class LazySegmentTree:
    __slots__ = 'n', 'height', 'size', 'idval', 'idlazy', 'op', 'apply', 'compose', 'tree', 'lazy'

    def __init__(self, nums, idval, idlazy, op, apply, compose):
        """
        Initialize the lazy segment tree.

        Args:
            nums: List of initial values
            idval: Identity value for the query operation
            idlazy: Identity value for lazy propagation (no-op value)
            op: Binary operation function (associative)
            apply: Function to apply lazy value to tree node
            compose: Function to compose two lazy values
        """
        self.n = len(nums)                          # Original array length
        self.height = (self.n-1).bit_length()       # Height of the tree (log2(n))
        self.size = 1 << self.height                # Size = 2^height (power of 2 >= n)
        self.idval = idval                          # Identity for queries
        self.idlazy = idlazy                        # Identity for lazy tags
        self.op = op                                # Query operation
        self.apply = apply                          # Apply lazy to node
        self.compose = compose                      # Compose two lazy values

        # Build the tree array: indices [size, size+n) store the leaf values
        # Indices [1, size) store internal nodes
        self.tree = [idval for _ in range(2 * self.size)]
        self.tree[self.size:self.size+self.n] = nums

        # Build internal nodes from bottom up
        for i in range(self.size-1, 0, -1):
            self.pushup(i)

        # Lazy array: stores pending updates for internal nodes
        # Only internal nodes [1, size) have lazy tags
        self.lazy = [idlazy for _ in range(self.size)]

    def pushup(self, rt):
        """
        Update parent node from its two children.
        Called after children nodes are modified.

        Tree structure:
        - Node rt has left child rt*2 and right child rt*2+1
        - Parent value = op(left_child, right_child)
        """
        self.tree[rt] = self.op(self.tree[rt*2], self.tree[rt*2+1])

    def pushdown(self, rt):
        """
        Push lazy tag from parent to children.
        This propagates pending updates down the tree.

        Process:
        1. Check if current node has a pending lazy tag
        2. Apply the lazy tag to both children
        3. Reset current node's lazy tag to identity
        """
        if self.lazy[rt] == self.idlazy:
            return  # No pending update

        # Apply lazy value to both children
        self.modify(rt*2, self.lazy[rt])
        self.modify(rt*2+1, self.lazy[rt])

        # Clear the lazy tag
        self.lazy[rt] = self.idlazy

    def set(self, idx, val):
        """
        Set value at index idx to val (point update).

        Process:
        1. Push down all lazy tags on the path from root to leaf
        2. Update the leaf value
        3. Push up to update all ancestors

        Args:
            idx: 0-indexed position in original array
            val: New value to set
        """
        idx += self.size  # Convert to tree index

        # Push down from root to leaf
        for i in range(self.height, 0, -1):
            self.pushdown(idx >> i)  # idx >> i gets the ancestor at level i

        self.tree[idx] = val

        # Push up from leaf to root
        for i in range(1, self.height + 1):
            self.pushup(idx >> i)

    def update(self, left, right, val):
        """
        Apply lazy update to range [left, right] (inclusive, 0-indexed).

        Process:
        1. Push down lazy tags on paths to left and right boundaries
        2. Apply updates to all nodes completely within range
        3. Push up to update ancestors of modified nodes

        Key insight: We only update O(log n) nodes, not all nodes in range.
        Nodes completely within range get lazy tags; partial nodes recurse.

        Args:
            left: Left boundary (inclusive, 0-indexed)
            right: Right boundary (inclusive, 0-indexed)
            val: Value to apply to the range
        """
        if left > right:
            return

        left += self.size   # Convert to tree indices
        right += self.size

        # Phase 1: Push down lazy tags on paths to boundaries
        for i in range(self.height, 0, -1):
            # Push down left boundary path if left is not at leftmost position of its level
            if left >> i << i != left:
                self.pushdown(left >> i)
            # Push down right boundary path if right+1 is not at leftmost position
            if (right+1) >> i << i != right+1:
                self.pushdown(right >> i)

        # Phase 2: Apply updates to nodes in range
        # Save original boundaries for phase 3
        l, r = left, right

        # Walk up the tree, updating nodes completely within range
        while left <= right:
            # If left is a right child, it's completely in range
            if left & 1:
                self.modify(left, val)
                left += 1
            # If right is a left child, it's completely in range
            if not right & 1:
                self.modify(right, val)
                right -= 1
            # Move to parent level
            left >>= 1
            right >>= 1

        # Phase 3: Push up to update ancestors
        left, right = l, r
        for i in range(1, self.height + 1):
            # Push up modified nodes on left boundary path
            if left >> i << i != left:
                self.pushup(left >> i)
            # Push up modified nodes on right boundary path
            if (right+1) >> i << i != right+1:
                self.pushup(right >> i)

    def modify(self, rt, val):
        """
        Apply a lazy value to node rt.

        For leaf nodes: directly apply to tree value
        For internal nodes: apply to tree value AND store in lazy tag

        Args:
            rt: Node index in tree array
            val: Lazy value to apply
        """
        # Apply the lazy value to the node's current value
        self.tree[rt] = self.apply(val, self.tree[rt])

        # If it's an internal node, compose with existing lazy tag
        if rt < self.size:
            self.lazy[rt] = self.compose(val, self.lazy[rt])

    def get(self, idx):
        """
        Get the current value at index idx (point query).

        Process:
        1. Push down all lazy tags on path from root to leaf
        2. Return the leaf value

        Args:
            idx: 0-indexed position in original array

        Returns:
            Current value at position idx
        """
        idx += self.size  # Convert to tree index

        # Push down all lazy tags on the path
        for i in range(self.height, 0, -1):
            self.pushdown(idx >> i)

        return self.tree[idx]

    def getall(self):
        """
        Get all values in the array.

        Process:
        1. Push down all lazy tags to ensure leaves are up-to-date
        2. Return the leaf portion of the tree array

        Returns:
            List of current values in the array
        """
        # Push down all internal nodes
        for idx in range(1, self.size):
            self.pushdown(idx)

        # Return only the valid portion (first n elements)
        return self.tree[self.size:self.size+self.n]

    def query(self, left, right):
        """
        Query the result of op over range [left, right] (inclusive, 0-indexed).

        Process:
        1. Push down lazy tags on paths to boundaries
        2. Accumulate results from nodes in range
        3. Combine left and right results respecting operation order

        Key insight: We maintain separate left and right accumulators
        to preserve the order of the associative operation.

        Args:
            left: Left boundary (inclusive, 0-indexed)
            right: Right boundary (inclusive, 0-indexed)

        Returns:
            Result of op applied to all elements in [left, right]
        """
        if left > right:
            return self.idval

        left += self.size
        right += self.size

        # Phase 1: Push down lazy tags on paths to boundaries
        for i in range(self.height, 0, -1):
            if left >> i << i != left:
                self.pushdown(left >> i)
            if (right+1) >> i << i != right+1:
                self.pushdown(right >> i)

        # Phase 2: Accumulate results
        # lres accumulates from left to right
        # rres accumulates from right to left (to preserve order)
        lres, rres = self.idval, self.idval

        while left <= right:
            # If left is a right child, include it in left accumulator
            if left & 1:
                lres = self.op(lres, self.tree[left])
                left += 1
            # If right is a left child, include it in right accumulator
            if not right & 1:
                rres = self.op(self.tree[right], rres)
                right -= 1
            # Move to parent level
            left >>= 1
            right >>= 1

        # Combine left and right results
        return self.op(lres, rres)

    def all(self):
        """
        Query the result over the entire array.

        Returns:
            Result of op applied to all elements (stored at root node)
        """
        return self.tree[1]

    def find_right(self, left, f):
        """
        Binary search: find the smallest index idx >= left such that
        f(query(left, idx)) is True.

        This is useful for finding thresholds, like:
        - First position where prefix sum >= target
        - First position where prefix max >= threshold

        Process:
        1. Start from left and accumulate values going right
        2. At each node, check if adding it would satisfy f
        3. If yes, descend to find exact position
        4. If no, skip this subtree and continue

        Args:
            left: Starting position (0-indexed)
            f: Predicate function that takes accumulated value

        Returns:
            Smallest idx in [left, n) where f(query(left, idx)) is True,
            or n if no such index exists
        """
        left += self.size
        lres = self.idval  # Accumulated result so far

        # Push down lazy tags on path to starting position
        for i in range(self.height, 0, -1):
            self.pushdown(left >> i)

        while True:
            # Move to rightmost node at current level that contains left
            while not left & 1:
                left >>= 1

            # Check if adding this node's subtree satisfies f
            if f(self.op(lres, self.tree[left])):
                # Found it! Descend to find exact leaf
                while left < self.size:
                    self.pushdown(left)
                    left *= 2  # Go to left child
                    # If left child doesn't satisfy, take it and try right child
                    if not f(self.op(lres, self.tree[left])):
                        lres = self.op(lres, self.tree[left])
                        left += 1
                return left - self.size

            # Check if we've reached the rightmost possible node
            if left & (left + 1) == 0:  # left is of form 2^k - 1
                return self.n

            # Accumulate this node and move to next
            lres = self.op(lres, self.tree[left])
            left += 1

    def find_left(self, right, f):
        """
        Binary search: find the largest index idx <= right such that
        f(query(idx, right)) is True.

        This is the left-side counterpart of find_right, useful for:
        - Last position where suffix sum >= target
        - Last position where suffix min <= threshold

        Process:
        1. Start from right and accumulate values going left
        2. At each node, check if adding it would satisfy f
        3. If yes, descend to find exact position
        4. If no, skip this subtree and continue

        Args:
            right: Ending position (0-indexed)
            f: Predicate function that takes accumulated value

        Returns:
            Largest idx in [0, right] where f(query(idx, right)) is True,
            or -1 if no such index exists
        """
        right += self.size
        rres = self.idval  # Accumulated result so far

        # Push down lazy tags on path to ending position
        for i in range(self.height, 0, -1):
            self.pushdown(right >> i)

        while True:
            # Move to leftmost node at current level that contains right
            while right > 1 and right & 1:
                right >>= 1

            # Check if adding this node's subtree satisfies f
            if f(self.op(self.tree[right], rres)):
                # Found it! Descend to find exact leaf
                while right < self.size:
                    self.pushdown(right)
                    right = 2 * right + 1  # Go to right child
                    # If right child doesn't satisfy, take it and try left child
                    if not f(self.op(self.tree[right], rres)):
                        rres = self.op(self.tree[right], rres)
                        right -= 1
                return right - self.size

            # Check if we've reached the leftmost possible node
            if right & (right - 1) == 0:  # right is a power of 2
                return -1

            # Accumulate this node and move to previous
            rres = self.op(self.tree[right], rres)
            right -= 1


# Example Usage:

# 1. Range Sum with Range Addition
def range_sum_with_addition():
    """
    Range sum queries with range addition updates.
    """
    nums = [1, 2, 3, 4, 5]

    # Identity: 0 for sum, 0 for addition
    # op: add two values
    # apply: add lazy value to current value
    # compose: combine two additions
    st = LazySegmentTree(
        nums=nums,
        idval=0,
        idlazy=0,
        op=lambda x, y: x + y,
        apply=lambda lazy, val: lazy + val,
        compose=lambda new, old: new + old
    )

    print("Initial sum [0, 4]:", st.query(0, 4))  # 15
    st.update(1, 3, 10)  # Add 10 to indices [1, 3]
    print("After update, sum [0, 4]:", st.query(0, 4))  # 45
    print("All values:", st.getall())  # [1, 12, 13, 14, 5]


# 2. Range Minimum with Range Assignment
def range_min_with_assignment():
    """
    Range minimum queries with range assignment updates.
    """
    nums = [5, 2, 8, 1, 9]
    INF = float('inf')

    # Identity: inf for min, inf for no assignment
    # op: minimum of two values
    # apply: assignment replaces value
    # compose: new assignment replaces old
    st = LazySegmentTree(
        nums=nums,
        idval=INF,
        idlazy=INF,
        op=lambda x, y: min(x, y),
        apply=lambda lazy, val: lazy if lazy != INF else val,
        compose=lambda new, old: new
    )

    print("Initial min [0, 4]:", st.query(0, 4))  # 1
    st.update(0, 2, 3)  # Set indices [0, 2] to 3
    print("After update, min [0, 4]:", st.query(0, 4))  # 1
    print("All values:", st.getall())  # [3, 3, 3, 1, 9]


# 3. Binary Search Example
def binary_search_example():
    """
    Find first position where prefix sum >= target.
    """
    nums = [1, 2, 3, 4, 5]
    st = LazySegmentTree(
        nums=nums,
        idval=0,
        idlazy=0,
        op=lambda x, y: x + y,
        apply=lambda lazy, val: lazy + val,
        compose=lambda new, old: new + old
    )

    target = 6
    idx = st.find_right(0, lambda x: x >= target)
    print(f"First index where prefix sum >= {target}: {idx}")  # 2
    print(f"Prefix sum [0, {idx}]:", st.query(0, idx))  # 6


if __name__ == "__main__":
    print("=== Example 1: Range Sum with Addition ===")
    range_sum_with_addition()
    print("\n=== Example 2: Range Min with Assignment ===")
    range_min_with_assignment()
    print("\n=== Example 3: Binary Search ===")
    binary_search_example()
