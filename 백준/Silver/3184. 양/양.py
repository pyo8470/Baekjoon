import sys
from collections import deque
input = sys.stdin.readline
direction = [(1,0),(-1,0),(0,1),(0,-1)]
R,C = map(int,input().split())
farm = [list(input().strip()) for i in range(R)]

def bfs(x,y):
    global lambs,wolves
    lamb_tmp,wolf_tmp = 0,0
    if farm[y][x] == 'v':
            wolf_tmp += 1
    elif farm[y][x] == 'o':
        lamb_tmp += 1
    queue = deque([(x,y)])
    farm[y][x] = '#'
    while queue:
        x,y = queue.popleft()
        for dx,dy in direction:
            nx,ny = x+dx,y+dy
            if 0 <= nx < C and 0 <= ny < R and farm[ny][nx] != '#':
                if farm[ny][nx] == 'v':
                    wolf_tmp += 1
                elif farm[ny][nx] == 'o':
                    lamb_tmp += 1
                farm[ny][nx] = '#'
                queue.append((nx,ny))
    if lamb_tmp > wolf_tmp :
        lambs += lamb_tmp
    else:
        wolves += wolf_tmp


lambs, wolves = 0,0
for y in range(R):
    for x in range(C):
        if farm[y][x] != '#':
            bfs(x,y)
print(lambs, wolves)