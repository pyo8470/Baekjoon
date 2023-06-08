# 한 계단 or 두 계단
# 연속된 세 계단 x
    # ->  즉 한칸 한칸 한칸 -> 불가능
N = int(input())

S = [int(input()) for i in range(N)]

# 계단이 두 개이하 인 경우
if N <= 2:
    print(sum(S))
else:
    # 세 개 이상인 경우
    dp = [0 for i in range(N)]
    # 두 번째 칸까지는 그냥 입력
    dp[0] = S[0]
    dp[1] = dp[0]+S[1]
    for i in range(2,N):
        # 3번째부터 
        #1. i-3전칸까지의 최대에서 i-2번째 칸을 밟지 않고 i-1, i칸을 연속적으로 밟는 경우
        #2. dp[i-2]까지의 최대에서 건너 뜀 ->S[i]칸
        dp[i] = max(dp[i-3]+S[i-1]+S[i],dp[i-2]+S[i])
    print(dp[-1])