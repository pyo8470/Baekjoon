import sys
import time
input = sys.stdin.readline
direction = [(0,-1),(1,0),(0,1),(-1,0)]
N,M = map(int,input().split())
## 0 : 북 1: 동 2: 남 3: 서
r,c,d = map(int,input().split())
maps = [list(map(int,input().split())) for i in range(N)]

count = 0

while(True):
    ## 현재 칸이 청소되지 않은 경우
    if maps[r][c] == 0:
        count+=1
        maps[r][c] = 2
    isCleaned = True
    for dx,dy in direction:
        nx,ny = c+dx,r+dy 
        if 0<=nx<M and 0<=ny<N:
            if maps[ny][nx] == 0:
                isCleaned = False
    if isCleaned:
        ## 바라보는 방향 유지한 채로 한 칸 후진
        k = (d+2)%4
        nx,ny = c+direction[k][0],r+direction[k][1]
        ## 가능한지
        if 0<=nx<M and 0<=ny<N:
            if maps[ny][nx] != 1:
                r,c = ny,nx
                # 1번으로 돌아감
                continue
            else:
                break
    ## 청소되지 않은 빈칸
    else:
        for i in range(4):
        ## 반시계 방향 회전
            d = (d-1)%4
            ## 앞 칸이 청소되지 않은 빈칸인 경우 한 칸 전진
            nx, ny = c+direction[d][0], r+direction[d][1]
            if 0<=nx<M and 0<=ny<N and maps[ny][nx] == 0:
                    r,c = ny,nx
                    break
    # t = maps[r][c]
    # maps[r][c] = 3
    # for i in maps:
    #     print(i)
    # maps[r][c] = t
    # time.sleep(0.5)
print(count)