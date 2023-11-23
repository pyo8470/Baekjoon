N = int(input())

dp=[]
for i in range(N):
    dp.append(list(map(int,input().split())))
    
## 대각선이 하나인 경우 
### i번째 행 의 맨 왼쪽 -> j=0인 경우
#### 계속 윗행(i-1)의 왼쪽, j=0인 경우만 더함

### i번쨰 행의 맨 오른쪽 -> j = i
#### 윗행(i-1)의 맨 오른쪽 j=i-1인 경우만 더함

## 대각선이 두개인 경우
#### 윗행(i-1)의 두 대각선중 큰 것을 더함
for i in range(1,N):
    for j in range(0,i+1):
        if j == 0:
            dp[i][j]+=dp[i-1][0]
        elif j==i:
            dp[i][j]+=dp[i-1][i-1]
        else:
            dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j])
print(max(dp[N-1]))
                    