import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

n = int(input())
dp = [0 for i in range(1000000)]

##  1 
##  00 11
##  001 100 111
##  0000 0011 1001 1100 1111
dp[0] = 1
dp[1] = 2
dp[2] = 3
for i in range(2,n):
    dp[i] = (dp[i-1] + dp[i-2])%15746
print(dp[n-1])