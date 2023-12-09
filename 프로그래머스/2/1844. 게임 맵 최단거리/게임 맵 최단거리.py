import sys
sys.setrecursionlimit(10**7)
## 하 우 상 좌
dx = [0,1,0,-1]
dy = [1,0,-1,0]

from collections import deque
def solution(maps):
    answer= 0
    n = len(maps[0])
    m = len(maps)

    visited = [[0]*n for i in range(m)]

    def BFS(x,y,r):
        q = deque()
        q.append([x,y,r])
        while q:
            [a,b,r] = q.popleft()
            if a < 0 or b < 0 or a > n - 1 or b > m - 1:
                continue
            if a == n-1 and b == m-1:
                return r
            if visited[b][a] == 0 and maps[b][a] == 1:  
                visited[b][a] = 1
                for i in range(4):
                    nx, ny = a+dx[i], b+dy[i]
                    q.append([nx,ny,r+1])
        return -1
        
    answer = BFS(0,0,1)
    return answer