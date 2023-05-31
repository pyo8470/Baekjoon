# 2468번 재밌겠다.
import sys
import copy
sys.setrecursionlimit(2_5000)
#위, 아래, 오른쪽 혹은 왼쪽
dx=[0,0,1,-1]
dy=[-1,1,0,0]
def dfs(x,y,depth):
    # 범위 이상하면
    if x<0 or y<0 or x>=N or y>=N:
        return False
    # 안전한 영역
    if Temp[x][y] >depth:
        # 이미 방문한 노드
        Temp[x][y]=depth
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            dfs(nx,ny,depth)
        return True
    return False
        
N = int(input())
Grid = []
s = set()
count = []
for i in range(N):
    k =list(map(int,input().split()))
    for i in k:
        s.add(i)
    Grid.append(k)
# 아무 지역도 물에 잠기지 않을 수도 있다.
s.add(min(s)-1)
for i in s:
    # Grid의 값이 계속 바뀜 -> Temp list에 깊은 복사
    Temp = copy.deepcopy(Grid)
    inCount=0
    for x in range(N):
        for y in range(N):
            if dfs(x,y,i) == True:
                inCount+=1
    count.append(inCount)
print(max(count))