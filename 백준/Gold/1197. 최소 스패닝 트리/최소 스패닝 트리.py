import sys
input = sys.stdin.readline

## Prim 알고리즘
import heapq
V,E = map(int,input().split())
graph = [[] for i in range(V+1)]
connected = [False] * (V+1)
for _ in range(E):
    start, end, weight = map(int,input().split())
    graph[start].append((weight,end))
    graph[end].append((weight,start))
answer = 0 
heap = []
heapq.heappush(heap,(0,1))
while heap:
    weight, vertex = heapq.heappop(heap)
    if not connected[vertex]:
        connected[vertex] = True
        answer+=weight
        for next_w, next_v in graph[vertex]:
            if not connected[next_v]:
                heapq.heappush(heap,(next_w,next_v))

print(answer)