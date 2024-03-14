import sys
input = sys.stdin.readline
from collections import deque
N = int(input())
graph = [[] for i in range(N+1)]
for i in range(N-1):
    root, child = map(int,input().split())
    graph[root].append(child)
    graph[child].append(root)
visited = [0 for i in range(N+1)]

### dfs
def dfs(v):
    for child in graph[v]:
        if not visited[child]:
            ### root 
            visited[child] = v
            dfs(child)
def bfs(v):
    visited[v] = True
    q = deque([v])
    while q:
        root = q.popleft()
        for child in graph[root]:
            if not visited[child]:
                q.append(child)
                visited[child] = root
                
bfs(1)
for i in visited[2:] :
    print(i)