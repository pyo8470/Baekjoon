M,N = map(int,input().split())
import sys
from collections import deque
bucket = [list(map(int,sys.stdin.readline().split()))for i in range(N)]
q = deque([])
direction = [(0,1),(1,0),(0,-1),(-1,0)]
for x in range(M):
    for y in range(N):
        if bucket[y][x] == 1:
            q.append([x,y])

## BFS
while q:
    x, y = q.popleft()
    for dx,dy in direction:
        nx,ny = x+dx,y+dy
        if 0<=nx<M and 0<=ny<N and bucket[ny][nx] == 0:
            bucket[ny][nx] = bucket[y][x] + 1
            q.append([nx,ny])
day = -1
for i in bucket:
    for tomato in i:
        if tomato == 0:
            print(-1)
            exit()
    day = max(day,max(i))

print(day-1)