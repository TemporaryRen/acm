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
    a,b = MII()
    if a%2 == 0 and b%2 == 0:
        print(a*(b//2) + 2)
    elif a%2 == 1 and b%2 == 1:
        print(a*b + 1)
    elif a%2 == 0 and b%2 == 1:
        print(-1)
    else:
        if b%4 == 0:
            print(a*(b//2) + 2)
        else:
            print(-1)
        

for _ in range(t):
    slove()