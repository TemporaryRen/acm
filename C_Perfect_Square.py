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
    matix = []
    for i in range(n):
        matix.append(I())
    ans = 0
    for i in range(n//2):
        for j in range(n//2):
            t = [(i,j),(n-1-j,i),(n-1-i,n-1-j),(j,n-1-i)]
            l = [matix[x][y] for x,y in t]
            l2 = [ord(x)  for x in l]
           
            mmax = max(l2)
            ssum = sum(l2)
            ans += mmax * 4 - ssum
            
    print(ans)

for _ in range(t):
    slove()