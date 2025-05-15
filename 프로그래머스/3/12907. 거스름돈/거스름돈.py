def solution(n, money):
    answer = 0
    dp = [1] + [0] * n
    for coin in money:
        for price in range(coin,n+1):
            ### 0 1 2 3 4 5
            ### 1 1 1 1 1 1 
            ### 1 1 2 2 3 3
            ### 1 1 2 2 3 4
            dp[price] += dp[price-coin]
    return dp[n]