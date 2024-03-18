import sys
from itertools import *
input = sys.stdin.readline
N,M = map(int,input().split())
L = list(map(int,input().split()))
result = []
# a = combinations_with_replacement(L,M)
# for i in a:
#     print(*i)
def dfs(k,start):
    if len(result) == M:
        print(' '.join(map(str,result)))
        return
    for i in range(N):
        if L[i] >= start:
            result.append(L[i])
            dfs(k+1,L[i])
            result.pop()
L.sort()
dfs(0,L[0])