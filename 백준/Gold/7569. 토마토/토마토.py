import sys
from  collections import deque
input = sys.stdin.readline
direction = [(1,0,0),(0,1,0),(-1,0,0),(0,-1,0),(0,0,1),(0,0,-1)]
M,N,H = map(int,input().split())
q =deque([])
Box = [[list(map(int,input().split())) for i in range(N)]for i in range(H)]
for x in range(M):
    for y in range(N):
        for z in range(H):
            if Box[z][y][x] == 1:
                q.append([x,y,z])

## BFS
while q:
    x, y, z= q.popleft()
    for dx,dy,dz in direction:
        nx,ny,nz = x+dx,y+dy,z+dz
        if 0<=nx<M and 0<=ny<N and 0<=nz<H and Box[nz][ny][nx] == 0:
            Box[nz][ny][nx] = Box[z][y][x] + 1
            q.append([nx,ny,nz])
day = -1
for z in range(H):
    for y in range(N):
        for x in range(M):
            count= Box[z][y][x] 
            if count == 0:
                print(-1)
                exit()
            else :
                day =max(count,day)
print(day-1)