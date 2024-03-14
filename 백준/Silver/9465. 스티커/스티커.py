import sys
input = sys.stdin.readline
for i in range(int(input())) :
    N = int(input())
    stickers = [list(map(int,input().split())) for i in range(2)]
    dp = [[0,0] for i in range(N+1)]
    dp[1] = [stickers[0][0],stickers[1][0]]
    ## 한 칸 뒤, 두 칸 뒤, 세 칸 뒤
    ## 한 칸 -> ㄱㄴ
    ## 두 칸 -> ㄱㄴ
    ## 세 칸 -> 건너 뛰면 대각 대각 대각으로 가는거랑 같음 -> 고민 x
    ## 대각선 비교
    ## 한 칸 뒤에서 오는 경우 vs 두 칸 뒤
        ## 
    for i in range(2,N+1):
        up = stickers[0][i-1]
        down = stickers[1][i-1]
        dp[i][0] = max(dp[i-1][1]+up,dp[i-2][1]+up)
        dp[i][1] = max(dp[i-1][0]+down,dp[i-2][0]+down)
    print(max(dp[N]))