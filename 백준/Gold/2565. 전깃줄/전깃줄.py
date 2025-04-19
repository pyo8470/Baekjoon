import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

N = int (input())
info = [list(map(int,input().split())) for i in range(N)]
info.sort(key=lambda x : x[0])

dp = [0] * N

count = 0
for i in range(N):
    dp[i] = 1
    ## 증가수열이 깨지면 전깃줄 자르기?
    for j in range(i):
        ## 증가수열의 길이 갱신
        if info[j][1] < info[i][1] and dp[j] + 1 > dp[i] :
            dp[i] = dp[j] + 1
print(N-max(dp))

