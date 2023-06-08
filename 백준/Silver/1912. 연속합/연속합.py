import sys
N=int(input())
S = list(map(int,sys.stdin.readline().split()))
dp=[0 for i in range(N)]
dp[0] = S[0]
for i in range(1,N):
    dp[i] = max(S[i],dp[i-1]+S[i])
print(max(dp))