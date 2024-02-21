N,M = map(int,input().split())
graph = [[0]*N for i in range(N)]
import sys
visited = [False]*N
count =0 

def dfs(node):
    visited[node] = True
    
    for i in range(N):
        if graph[node][i] == 1 and not visited[i]:
            dfs(i)      
def bfs(node):
    from collections import deque
    q = deque([node]) 
    visited[node] = True
    
    while q:
        v = q.popleft()
        for i in range(N):
            if not visited[i] and graph[v][i] == 1:
                q.append(i)
                visited[i] = True
for i in range(M):
    u,v = map(int,sys.stdin.readline().split())
    graph[u-1][v-1] = 1
    graph[v-1][u-1] = 1

for i in range(N):
    if not visited[i]:
        bfs(i)
        count += 1

print(count)