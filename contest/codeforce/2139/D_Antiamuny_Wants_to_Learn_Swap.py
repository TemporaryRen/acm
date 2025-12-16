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
    n,q = MII()
    a = LII()
    l = [-1] * n
    r = [n] * n
    st = []
    for i,x in enumerate(a):
        while st and x > a[st[-1]]:
            st.pop()
        if st:
            l[i] = st[-1]
        st.append(i)
    st = []
    for i in range(n-1,-1,-1):
        x = a[i]
        while st and x < a[st[-1]]:
            st.pop()
        if st:
            r[i] = st[-1]
        st.append(i)
    f = [n] * n
    for i in range(1,n-1):
        if l[i] != -1 and r[i] != n:
            f[l[i]] = min(f[l[i]],r[i])
    for i in range(n-2,-1,-1):
        f[i] = min(f[i],f[i+1])
    for _ in range(q):
        x,y = MII()
        x -= 1
        y -= 1
        if y < f[x]:
            print('YES')
        else:
            print('NO')
        
for _ in range(t):
    slove()