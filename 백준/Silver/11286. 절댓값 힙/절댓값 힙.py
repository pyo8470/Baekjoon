import heapq

heap = []
minusheap = []
N = int(input())
import sys 
for i in range(N):
    num = int(sys.stdin.readline())
    
    if num != 0:
        if num<0:
            heapq.heappush(heap,[-num,num])
        else:
            heapq.heappush(heap,[num,num])
            
    else:
        if len(heap) == 0:
            print(0)
        else:
            print(heapq.heappop(heap)[1])
