import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

dp = [[[[] for _ in range(21)] for _ in range(21)] for _ in range(21)]


a,b,c = map(int,input().split())


for i in range(21):
    for j in range(21):
        dp[0][i][j] = 1
        dp[i][0][j] = 1
        dp[i][j][0] = 1
        
for i in range(1,21):
    for j in range(1,21):
        for k in range(1,21):
            if i<j and j<k:
                dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k]
            else:
                dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1]
def w(a,b,c):
    if a <= 0 or b <= 0 or c <= 0:
        return dp[0][0][0]
    if a > 20 or b > 20 or c > 20:
        return dp[20][20][20]
    else:
        return dp[a][b][c]
while a != -1 or b!= -1 or c != -1:
    print(f"w({a}, {b}, {c}) = {w(a,b,c)}")
    a,b,c = map(int,input().split())
    