
import itertools
direction = [(1,0),(-1,0),(0,1),(0,-1)]
for _ in range(1,int(input())+1):
    N,M = map(int,input().split())
    balloons = [list(map(int,input().split())) for i in range(N)]
    pollen = [[0]*M for i in range(N)]
    for y in range(N):
        for x in range(M):
            for dx,dy in direction:
                ny,nx = y+dy, x+dx
                if not (nx<0 or ny<0 or nx>=M or ny>=N):
                    pollen[y][x] += balloons[ny][nx]
            pollen[y][x] += balloons[y][x]
    print(f'#{_} {max(itertools.chain(*pollen))}')