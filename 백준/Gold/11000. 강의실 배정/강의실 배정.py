import sys
input = sys.stdin.readline
from collections import deque
import heapq as hp
N = int(input())
time = deque(sorted([list(map(int,input().split())) for i in range(N)], key=lambda x : (x[0],x[1])))
heap = []
hp.heappush(heap,time.popleft()[1])
while time:
    ## 남은 강의
    start,end = time.popleft()
    ## 현재 강의가 끝나는 시간
    specific_time = hp.heappop(heap)
    
    ## 현재 강의가 더 늦게 끝나는 경우
    if start < specific_time:
        hp.heappush(heap,specific_time)
        hp.heappush(heap,end)
    else:
        hp.heappush(heap,end)

print(len(heap))