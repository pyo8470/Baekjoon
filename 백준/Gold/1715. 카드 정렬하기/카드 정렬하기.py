import sys
input = sys.stdin.readline
import heapq
N = int(input())
heap =[int(input()) for i in range(N)]
heapq.heapify(heap)
count = 0
while len(heap) >= 2 :
    first, second = heapq.heappop(heap), heapq.heappop(heap)
    heapq.heappush(heap,first+second)
    count+=(first+second)
print(count)