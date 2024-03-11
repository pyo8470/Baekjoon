import sys,copy
from collections import deque
input = sys.stdin.readline
N = int(input())
G = [list(map(int,input().split())) for i in range(N)]
answer = copy.deepcopy(G)

def bfs(x):
    global answer
    q = deque()
    q.append(x)
    visited = [False for i in range(N)]
    
    while q:
        k = q.popleft()
        
        for i in range(N):
            ## 아직 방문하지 않은 노드
            if not visited[i] and G[k][i] == 1:
                q.append(i)
                visited[i] = True
                ## 양수인 경로가 있으므로 1 표시
                answer[x][i] = 1

for i in range(N):
    bfs(i)

for i in answer:
    print(*i)