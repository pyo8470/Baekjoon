import sys
import copy
sys.setrecursionlimit(2_5000)
def dfs(x,y,Grid:list[list],color:str):
    # 이상한 범위
    if x<0 or y<0 or x>=N or y>=N:
        return False
    # 방문한 노드를 어떻게 처리를 해야할까
    # 널로 처리해버리자
    if Grid[x][y] == color:
        Grid[x][y] = ''
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            dfs(nx,ny,Grid,color)
        return True
    return False
#위, 아래, 오른쪽 혹은 왼쪽
dx=[0,0,1,-1]
dy=[-1,1,0,0]
COLOR1 =['R','G','B']
COLOR2 =['R','B']

N = int(input())
GridForNot = []
GridForWeak=[]
for i in range(N):
    k = list(input())
    GridForNot.append(k)
    GridForWeak=copy.deepcopy(GridForNot)
for i in range(N):
    for j in range(N):
        if GridForWeak[i][j] == 'G':
            GridForWeak[i][j] = 'R'
            
count1=0
count2=0
for color in COLOR1:
    for x in range(N):
        for y in range(N):
            if dfs(x,y,GridForNot,color) == True:
                count1+=1
for color in COLOR2:
    for x in range(N):
        for y in range(N):            
            if dfs(x,y,GridForWeak,color) == True:
                count2+=1    
print(count1,count2)

