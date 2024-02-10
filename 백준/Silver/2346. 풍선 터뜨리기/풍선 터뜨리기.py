N = int(input())
from collections import deque
import sys
q=deque(enumerate(map(int,sys.stdin.readline().split())))

for i in range(N):
    idx, tmp =q.popleft()
    print(idx +1 , end=' ')
    if tmp>0:
        q.rotate(-(tmp-1))
    else:
        q.rotate(-tmp)