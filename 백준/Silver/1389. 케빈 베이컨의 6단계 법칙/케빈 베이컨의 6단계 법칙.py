N,M = map(int,input().split())
import sys
from collections import deque
matrix = [[] for i in range(N)]
result = []

for i in range(M):
    A,B = map(int,sys.stdin.readline().split())
    matrix[A-1].append(B-1)
    matrix[B-1].append(A-1)
def bfs(start):
    visited = [-1] * N
    
    q=deque()
    q.append(start)
    visited[start] = 0
    
    while q :
        v = q.popleft()
        
        for next in matrix[v]:
            if visited[next] == -1:
                visited[next] = visited[v]+1
                q.append(next)
    return sum(visited)
                
min_result = float("INF")
answer=0
for i in range(N):
    result= bfs(i)
    if result < min_result:
        min_result=result
        answer = i+1
print(answer)