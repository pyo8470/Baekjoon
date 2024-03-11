## 빈 칸 0 , 치킨집 1 , 집 2
## (r,c)
## 거리 -> 유클리드 거리
from itertools import combinations
import sys
N,M = map(int,input().split())
maps = [list(map(int,input().split())) for i in range(N)]
kfc= []
for y in range(N):
    for x in range(N):
        if maps[y][x] == 2:
            kfc.append((y,x))
## 치킨집을 M개 선택한 조합의 갯수
combi =list(combinations(kfc,M))
min_dis = sys.maxsize
for k in combi:
    ## 모든 조합에 대하여
    dis = 0
    for y in range(N):
        for x in range(N):
            if maps[y][x] == 1:
                ## 하나의 집에 대해 M개의 치킨 거리를 구함
                temp_dis = []
                for coor in k:
                    ny,nx = coor[0], coor[1]
                    temp_dis.append(abs(ny-y) + abs(nx-x))
                ## 하나의 집에 대해서 가장 작은 치킨 거리를 더함
                dis += min(temp_dis)
    ## 합한 치킨 거리 중 최소를  구하기
    if dis < min_dis:
        min_dis = dis
print(min_dis)