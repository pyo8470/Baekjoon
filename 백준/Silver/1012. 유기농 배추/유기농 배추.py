import sys
from collections import deque
input = sys.stdin.readline
direction = [(1,0),(-1,0),(0,1),(0,-1)]

def bfs(x,y):
    queue = deque([(x, y)])
    visited[y][x] = 1
    while queue:
        
        x,y = queue.popleft()
        for dx,dy in direction:
            nx,ny = x+dx,y+dy
            if 0<=nx<M and 0<=ny<N and farmland[ny][nx] and not visited[ny][nx]:
                visited[ny][nx] = 1
                queue.append((nx,ny))
            
direction = [(1,0),(-1,0),(0,1),(0,-1)]
for i in range(int(input())):
    M,N,K = map(int,input().split())
    farmland = [[0]*M for i in range(N)]
    visited = [[0]*M for i in range(N)]
    count = 0
    for i in range(K):
        x,y = map(int,input().split())
        farmland[y][x] = 1
    for y in range(N):
        for x in range(M):
            if farmland[y][x] and not visited[y][x]:
                bfs(x,y)
                count+=1
    print(count)