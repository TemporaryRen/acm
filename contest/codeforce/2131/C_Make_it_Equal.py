packages = 1
def I():
    return input()
def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def LFI():
    return list(map(float, input().split()))
def GMI():
    return map(lambda x: int(x) - 1, input().split())
def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

if packages:
    from io import BytesIO, IOBase
    import random
    import os
    import bisect
    import typing
    from collections import Counter, defaultdict, deque
    from copy import deepcopy
    from functools import cmp_to_key, lru_cache, reduce
    from heapq import merge, heapify, heappop, heappush, heappushpop, nlargest, nsmallest
    from itertools import accumulate, combinations, permutations, count, product
    from operator import add, iand, ior, itemgetter, mul, xor
    from string import ascii_lowercase, ascii_uppercase, ascii_letters
    from typing import *


t = II()

def solve():
    n,k = MII()
    s = LII()
    t = LII()
    for i in range(n):
        t[i] = min(t[i] % k, k-t[i]%k)
        s[i] = min(s[i] % k, k-s[i]%k)
    s.sort()
    t.sort()
    for x,y in zip(s,t):
        if x != y:
            print("NO")
            return
    print("YES")

for _ in range(t):
    solve()
    