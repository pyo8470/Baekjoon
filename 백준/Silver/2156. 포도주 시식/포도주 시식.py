
N=int(input())
dp = [0 for _ in range(3)]
a=[0 for _ in range(3)]
for i in range(N):
    if i >= 3 :
        a.append(int(input()))
    else:    
        a[i]= int(input())
## i번 째를 마신다
#### 두번 연속 마신 경우 -> i-1를 마심
###### i-2를 마시지 않음 -> i-3까지의 최대와 i-1 + i
###### dp[i] = dp[i-3] + a[i-1]+a[i]
#### 두 번 연속 마시지 않은 경우-> i-1를 마시지 않음
###### dp[i]= dp[i-2] + a[i]
## i번 째를 마시지 않음
#### dp[i] = d[i-1]

dp[0] = a[0]
dp[1] = dp[0]+a[1]
dp[2] = max(a[0]+a[2],a[1]+a[2],dp[1])

for i in range(3,N):
    
    dp.append(max(a[i]+a[i-1]+dp[i-3],a[i]+dp[i-2]))
    dp[i] = max(dp[i],dp[i-1])
print(max(dp))   