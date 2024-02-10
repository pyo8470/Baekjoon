N = int(input())
# 1~N 까지의 카드
from collections import deque
queue = deque(i for i in range(1,N+1))
while len(queue) > 1:
    queue.popleft()
    back = queue.popleft()
    queue.append(back)
print(queue[0])