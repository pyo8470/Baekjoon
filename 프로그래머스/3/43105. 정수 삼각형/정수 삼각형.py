def solution(triangle):
    answer = 0
    dp = [[triangle[0][0]]]
    
    for i in range(1,len(triangle)):
        k = []
        for j in range(i+1):
            ## 첫자리
            if j == 0 :
                k.append(dp[i-1][j]+triangle[i][j])
            elif j == i :
                k.append(dp[i-1][j-1]+triangle[i][j])
            else:
                temp = max(dp[i-1][j],dp[i-1][j-1])
                k.append(temp+triangle[i][j])
        dp.append(k)
    answer = max(dp[-1])
    return answer