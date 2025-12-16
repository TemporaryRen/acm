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

def slove():
    n = II()
    g = [[] for _ in range(n)]
    indgree = [0] * n
    for i in range(n-1):
        u,v = MII()
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
        indgree[v] += 1
        indgree[u] += 1
    if n < 3:
        print(0)
        return
    leaves = sum([x == 1 for x in indgree])
    mx = max([sum([indgree[x] == 1 for x in g[u]]) for u in range(n)])
    print(leaves - mx)
for _ in range(t):
    slove()