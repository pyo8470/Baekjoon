import sys
import heapq
from collections import deque
input = sys.stdin.readline
for _ in range(int(input())):
    k = int(input())   
    maxHeap =  []
    minHeap = []
    visit = [False]*k
    ## D or I
    for i in range(k):
        operation, num = map(str,input().split())
        num = int(num)
        if operation == 'I':
            heapq.heappush(minHeap,(num,i))
            heapq.heappush(maxHeap,(-num,i))
            visit[i] = True
        
        else:
            if num == 1:
                while maxHeap and not visit[maxHeap[0][1]]:
                    heapq.heappop(maxHeap)
                if maxHeap:
                    visit[maxHeap[0][1]] = False
                    heapq.heappop(maxHeap)
            else:
                while minHeap and not visit[minHeap[0][1]]:
                    heapq.heappop(minHeap)
                if minHeap:
                    visit[minHeap[0][1]] = False
                    heapq.heappop(minHeap)

    while minHeap and not visit[minHeap[0][1]]:
        heapq.heappop(minHeap)
    while maxHeap and not visit[maxHeap[0][1]]:
        heapq.heappop(maxHeap)
    if not maxHeap or not minHeap:
        print('EMPTY')
    else:
        print(-maxHeap[0][0],minHeap[0][0])