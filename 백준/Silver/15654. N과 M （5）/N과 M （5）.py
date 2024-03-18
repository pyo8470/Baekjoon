import sys
from itertools import *
input = sys.stdin.readline
N,M = map(int,input().split())
L = list(map(int,input().split()))
result = []
# a = combinations(L,M)
# for i in a:
#     print(*i)
def dfs(start):
    if len(result) == M:
        print(' '.join(map(str,result)))
        return
    for i in L:
        if i not in result:
            result.append(i)
            dfs(i)
            result.pop()
L.sort()
dfs(L[0])