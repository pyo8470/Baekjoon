import sys
input = sys.stdin.readline
## 앞 상자의 크기 < 뒷 상자 -> 앞 상자를 뒷 상자에 넣는다

n = int(input())
boxes = list(map(int,input().split()))

dp = [1 for _ in range(n)]

for i in range(1,n):
    for j in range(i):
        if boxes[i] > boxes[j]:
            dp[i] = max(dp[i],dp[j]+1)

print(max(dp))