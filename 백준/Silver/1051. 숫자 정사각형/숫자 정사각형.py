N,M =map(int,input().split())
Sqaure = [input() for i in range(N)]
Result = []
for garo in range(N):
    for sero in range(M):
        cur = Sqaure[garo][sero]
        # 세로축 기준으로 탐색
        for index in range(sero,M): 
            ## 일단 같은 가로축에 같은 수가 있는지 확인
            if cur ==Sqaure[garo][index]:
                ## 정사각형의 길이
                length = index-sero
                ## 세로로 확장했을 때, 범위가 넘어가는지 확인
                if garo + (index-sero) <N:
                    if cur == Sqaure[garo+length][sero] and cur == Sqaure[garo+length][index]:
                        Result.append((length+1)**2)
print(max(Result))