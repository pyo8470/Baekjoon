# 2178 미로 탐색
from collections import deque
## bfs -> 최단 경로
def bfs(x,y):
    count = 1
    ## 상하좌우 움직임 
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    queue = deque()
    queue.append([x,y])
    while len(queue) != 0:
        x,y=queue.popleft()
        ## 상하좌우의 경우
        for i in range(4):
            nextX=x+dx[i]
            nextY=y+dy[i]
            if x==M-1 and y == N-1:
                print(Graph[N-1][M-1])
                break
            if 0<=nextX<M and 0<=nextY<N:
                if(not visited[nextY][nextX] and Graph[nextY][nextX]==1):
                    Graph[nextY][nextX]=Graph[y][x]+1
                    queue.append([nextX,nextY])
                    visited[nextY][nextX] = True
N,M = map(int,input().split())
# N x M 방문 유무 확인 행렬 생성
visited = [[False] * M for _ in range(N)]
Graph =[list(map(int,input().strip()))for i in range(N)]
bfs(0,0)
