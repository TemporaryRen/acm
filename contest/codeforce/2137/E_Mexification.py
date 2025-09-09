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

def cmex(s):
    cmex = len(s)
    cnt = defaultdict(int)
    for x in s:
        cnt[make_key(x)] += 1
    for i in count():
        if not cnt[make_key(i)]:
            cmex = i 
            break
    ret = []
    for x in s:
        if cnt[make_key(x)] == 1:
            ret.append(min(cmex,x))
        else:
            ret.append(cmex)
    return ret
'''
三种情况：
1:0 1 2 3 4 5 ... 直接是 0～n-1 的序列 -> 永远不变
2:0 1 2 2 3 4 ... 0～x - 1 的序列 + 多个 x -> 计算 3 次后 2 3 2 3 循环
3:0 1 3 4 5 6 ... 0~x-1 的序列 + x+1 缺 x 计算 2 次后 1 2 1 2 循环

=> 最多计算 3 次
'''
def slove():
    n,k = MII()
    a = LII()
    if k > 3:
        k -= 1
        if k&1:
            k = 2
        else:
            k = 3
    for _ in range(k):
        a = cmex(a)
    print(sum(a))
        
    
    

for _ in range(t):
    slove()