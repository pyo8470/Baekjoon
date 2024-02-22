N,M = map(int,input().split())
import sys
room = [list(sys.stdin.readline().strip())for i in range(N)]
from collections import deque

visited = [[False]*M for i in range(N)]
for i in range(M):
    for j in range(N):
        if room[j][i] == 'I':
            x,y = i,j
            visited[j][i] = True

direction = [(0,1),(1,0),(-1,0),(0,-1)]
count = 0
q= deque()

## BFS
q.append([x,y])
while q :
    x,y = q.popleft()
    for dx,dy in direction:
        nx,ny = x+dx,y+dy
        if 0<= nx < M and 0<= ny< N :
            if not visited[ny][nx] and room[ny][nx] != 'X':
                q.append([nx,ny])
                visited[ny][nx] = True

                if room[ny][nx] == 'P':
                    count+=1

print(count if count >= 1 else 'TT')