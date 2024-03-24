import sys
import copy
input = sys.stdin.readline

N,M = map(int,input().split())
table = [list(map(int,input().split())) for i in range(N)]
dp = [[0 for i in range(N+1)] for i in range(N+1)]
## 구간 합 구하는 법
for y in range(1,N+1):
    for x in range(1,N+1):
        dp[x][y] = dp[x-1][y] + dp[x][y-1] - dp[x-1][y-1] + table[x-1][y-1]

for _ in range(M):
    x1,y1,x2,y2 = map(int,input().split())
    result = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]
    print(result)