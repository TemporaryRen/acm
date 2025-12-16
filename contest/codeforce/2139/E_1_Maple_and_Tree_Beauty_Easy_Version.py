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
    import math
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
RANDOM = random.randrange(2**62)
def make_key(x):
    return hash(x) ^ RANDOM

t = II()

def slove():
    n,k = MII()
    a = LII()
    g = [[] for _ in range(n)]
    for i,x in enumerate(a):
        g[x-1].append(i+1)
    lvl = [1]
    q = []
    q.append(0)
    all_child = True
    while q and all_child:
        l = []
        for p in q:
            for nxt in g[p]:
                l.append(nxt)
                if len(g[nxt]) == 0:
                    all_child = False
        if l:
            lvl.append(len(l))
        q = l
    y = n - k
    dp = [True] + [False] * n
    ssum = sum(lvl)
    for x in lvl:
        ndp = dp[::]
        for j in range(x,n+1):
            ndp[j] = ndp[j] or dp[j-x]
        dp = ndp

    ans = len(lvl) - 1
   
    for i in range(ssum + 1):
        if dp[i] and i <= k and ssum - i <= y:
            ans += 1
            break
            
   
    print(ans)
    

for _ in range(t):
    slove()