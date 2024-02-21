N = int(input())
import sys
import heapq

heap = []

## heapq 작동 방식을 잘 알자
for i in range(N):
    num = int(sys.stdin.readline())
    if num != 0:
        heapq.heappush(heap,num)

    else:
        if heap:
            print(heapq.heappop(heap))
        else:
            print(0)