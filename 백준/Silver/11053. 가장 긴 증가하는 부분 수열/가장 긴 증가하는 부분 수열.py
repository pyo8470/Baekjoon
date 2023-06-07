N = int(input())
A = list(map(int,input().split(" ")))
dp = [1 for i in range(N)]
# dp[i] = A[i]를 마지막 값으로 가지는 부분수열의 길이
for i in range(1,N):
    for j in range(i):
        if A[i] > A[j]:
            dp[i]=max(dp[i],dp[j]+1)
print(max(dp))