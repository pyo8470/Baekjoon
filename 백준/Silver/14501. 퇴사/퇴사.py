# 14501 퇴사

N = int(input())
# 상담하는데 걸리는 기간
T=[] 
# 상담헀을 때 받을 수 있는 금액
P=[]
#입력 단계
for i in range(N):
    t,p=map(int,input().split())
    T.append(t)
    P.append(p)
# 조건 1. 상담일은 기한을 넘길 수 없다.
# 조건 2. 최대이익을 구한다
max_profit = 0

dp=[0 for i in range(N+1)] # 이익들
# i가 의미하는 것 -> 1일차, 2일차
for i in range(N):
    # 1일차부터 최대를 누적시켜간다
    for j in range(i+T[i],N+1):
        if dp[j] < dp[i] + P[i] :
            dp[j] = dp[i] + P[i] 
print(dp[N])

