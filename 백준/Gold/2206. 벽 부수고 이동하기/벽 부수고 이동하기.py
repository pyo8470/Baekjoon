import sys
from collections import deque
input = sys.stdin.readline

direction = [(1, 0), (-1, 0), (0, 1), (0, -1)]
N, M = map(int, input().split())
board = [list(map(int, input().strip())) for _ in range(N)]

queue = deque([(0, 0, 1, False)])
visited = set([0,0,False])
answer = -1

while queue:
    x, y, count, broken = queue.popleft()

    if x == M - 1 and y == N - 1:
        answer = count
        break

    for dx, dy in direction:
        nx, ny = x + dx, y + dy

        if 0 <= nx < M and 0 <= ny < N and (nx,ny,broken) not in visited:
            if board[ny][nx] == 0:
                queue.append((nx, ny, count + 1, broken))
                visited.add((nx,ny,broken))
            elif not broken:
                queue.append((nx,ny,count+1,True))
                visited.add((nx,ny,True))
print(answer)
