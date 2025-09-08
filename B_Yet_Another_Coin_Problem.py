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
coins = [1,3,6,10]
def slove():
    n = II()
    ans = n
    for cnt1 in range(3):
        for cnt3 in range(2):
            for cnt6 in range(5):
                for cnt10 in range(3):
                    t = cnt1 + cnt3 + cnt6 + cnt10
                    s = n - (cnt1 + cnt3*3 + cnt6*6 + cnt10 * 10)
                    if s >= 0 and s%15 == 0:
                        ans = min(ans,t+s//15)
            
                    
    print(ans)

for _ in range(t):
    slove()