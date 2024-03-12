import sys
from collections import deque
input = sys.stdin.readline
N,M = map(int,input().split())
ladder={}
snake ={}
for i in range(N):
    a,b = map(int,input().split())
    ladder[a] = b
for i in range(M):
    a,b = map(int,input().split())
    snake[a] = b
    
## BFS
game = [0 for i in range(101)]
visited = [False for i in range(101)]
q = deque([1])
count = 0
while q:
    now = q.popleft()
    if now == 100:
        print(game[now])
        # for i in range(1,101):
        #     print(i," : ",game[i],end=' ')
        #     if i % 10 == 0:
        #         print()
        break
    for i in range(1,7):
        next_number = now + i 
        if next_number <= 100 and not visited[next_number]:
            if next_number in ladder.keys():
                next_number = ladder[next_number]
            if next_number in snake.keys():
                next_number = snake[next_number] 
            if not visited[next_number]:
                visited[next_number] = True
                game[next_number] = game[now] + 1
                q.append(next_number)