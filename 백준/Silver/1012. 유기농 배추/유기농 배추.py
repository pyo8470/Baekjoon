import sys    
sys.setrecursionlimit(5_000)  # 좀 넉넉하게, 더 크게 주셔도 됩니다.
def dfs(x,y):
    # 범위 벗어난 경우
    if x<0 or y<0 or x>=M or y>=N:
        return False
    if Grid[y][x] == 1:
        Grid[y][x] = 0
        dfs(x+1,y)
        dfs(x-1,y)
        dfs(x,y+1)
        dfs(x,y-1)
        return True
    return False
T=int(input())
for i in range(T):
    result =0
    M,N,K =map(int,input().split())
    Grid = [[0 for i in range(M)]for j in range(N)]
    for i in range(K):
        Y,X=map(int,input().split())
        Grid[X][Y]=1
    for i in range(M):
        for j in range(N):
            if dfs(i,j) == True:
                result += 1
    print(result)
