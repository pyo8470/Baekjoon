import sys
sys.setrecursionlimit(1_0000)
dx = [-1,1,0,0,1,1,-1,-1]
dy = [0,0,-1,1,1,-1,1,-1]
def dfs(x,y):
    # 범위를 벗어나는 경우
    
    if x<0 or y<0 or x>=w or y>=h:
        return False
    if Grid[y][x] == 1:
        Grid[y][x] = 0
        for i in range(8):
            nx=x+dx[i]
            ny=y+dy[i]
            dfs(nx,ny)
        return True
    return False
    
while(True):
    result = 0
    w,h = map(int,input().split())
    if w == 0 and h == 0 :
        break
    Grid = []
    for i in range(h):
        Grid.append(list(map(int,input().split())))
    for x in range(w):
        for y in range(h):
            if dfs(x,y) == True:
                result+=1
    print(result)