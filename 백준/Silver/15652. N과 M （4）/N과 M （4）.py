import sys
from itertools import *
input = sys.stdin.readline
N,M = map(int,input().split())
result = []
L = list(i for i in range(1,N+1))
a = combinations_with_replacement(L,M)
for i in a:
    print(*i)
# def dfs(start):
#     if len(result) == M:
#         print(' '.join(map(str,result)))
#         return
#     for i in range(start,N+1):
#             result.append(i)
#             dfs(i)
#             result.pop()
# dfs(1)