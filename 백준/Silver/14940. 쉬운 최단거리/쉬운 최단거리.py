n, m = map(int,input().split())
import sys
map = [list(map(int,sys.stdin.readline().split()))for i in range(n)]
result = [[-1 for i in range(m)] for i in range(n)]
visited = [[0]*m for i in range(n)]
direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]  # 상하좌우

from collections import deque
q= deque([])
for i in range(m):
    for j in range(n):
        if map[j][i] == 0:
            result[j][i] = 0
        if map[j][i] == 2:
            ## 도착지점
            q.append((i,j))
            visited[j][i] = 1 
            result[j][i] = 0

while q:
    x,y = q.popleft()
    
    for dx,dy in direction:
        nx,ny = x+dx,y+dy
        
        if 0<=nx<m and 0<=ny<n and visited[ny][nx] == 0 and map[ny][nx] == 1:
            q.append((nx,ny))
            visited[ny][nx] = 1
            result[ny][nx] = result[y][x] + 1
            
for row in result:
    for i in row:
        print(i,end=" ")
    print()
