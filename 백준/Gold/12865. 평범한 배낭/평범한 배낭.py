# W -> 가방의 구메
# n -> 보석의 수
def knapsack(W,wt,val,N):
    dp = [[0 for i in range(W+1)] for k in range(N+1)]
    for i in range(N+1):
        for w in range(W+1):
            if i == 0 or w==0 :
                dp[i][w]=0
            elif wt[i-1] <=w:
                dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w])
            else:
                dp[i][w]=dp[i-1][w]
    return dp[N][W]
N, K=map(int,input().split())
wt=[]
val=[]
# dp[i]  -> 
for i in range(N):
    W,V =map(int,input().split())
    wt.append(W)
    val.append(V)
print(knapsack(K,wt,val,N))
