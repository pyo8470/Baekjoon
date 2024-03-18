import sys
from itertools import combinations
input = sys.stdin.readline
N,M = map(int,input().split())
result = []
# L = list(i for i in range(1,N+1))
# a = combinations(L,M)
# for i in a:
#     print(*i)
def dfs(start):
    if len(result) == M:
        print(' '.join(map(str,result)))
        return
    for i in range(start,N+1):
        if i not in result:
            result.append(i)
            dfs(i)
            result.pop()
dfs(1)