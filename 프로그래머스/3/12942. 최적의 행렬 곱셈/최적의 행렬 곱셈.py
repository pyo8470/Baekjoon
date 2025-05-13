def solution(matrix):
    ## 최소공배수 
    n = len(matrix)
    DP = [[0 for i in range(len(matrix))] for j in range(len(matrix))]
    
    # i번째부터 j번째 행렬까지 곱하는 최소 연산 수
    
    for length in range(1,n): ## 길이
        for i in range(n-length): ## 시작 인덱스
            j = i+length
            DP[i][j] = float('inf')
            for k in range(i,j):
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1])
    return DP[0][n-1]