N, K = map(int,input().split()) 
import sys
from collections import deque
def bfs(x):
    q = deque([x])
    
    while q:
        x = q.popleft()
        if x == K:
            return visited[x] 
        for i in (x+1,x-1,2*x):
            if 0 <= i <= 100000 and not visited[i]:
                visited[i] = visited[x] + 1
                q.append(i)
visited = [0 for i in range(100001)]    
print(bfs(N))