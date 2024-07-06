import sys
from collections import deque
input = sys.stdin.readline
N= int(input())
queue = deque([i for i in range(N,0,-1)])
while len(queue) >=2 :
    queue.pop()
    k = queue.pop()
    queue.appendleft(k)
print(*queue)
