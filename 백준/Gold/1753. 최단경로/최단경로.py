import sys
input = sys.stdin.readline

V,E = map(int,input().split())
start = int(input())
graph = [[] for i in range(V+1)]
for _ in range(E):
    s,e,w = map(int,input().split())
    graph[s].append((w,e))
import heapq as hq
answer = [sys.maxsize] * (V+1)
answer[start] = 0
heap = []
hq.heappush(heap,(0,start))
while heap:
    
    weight, vertex = hq.heappop(heap)
    if weight <= answer[vertex]:
        for w,next_v in graph[vertex]:
            next_w = weight+w
            if next_w < answer[next_v]:
                answer[next_v] = next_w
                hq.heappush(heap,(next_w,next_v))
for ans in answer[1:]:
    ans = 'INF' if ans == sys.maxsize else ans
    print(ans)