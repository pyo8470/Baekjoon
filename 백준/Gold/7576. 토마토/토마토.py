import sys
from collections import deque
input = sys.stdin.readline

# 방향 벡터 설정 (오른쪽, 왼쪽, 아래, 위)
direction = [(0,1), (0,-1), (1,0), (-1,0)]

# M: 가로 칸 수, N: 세로 칸 수
M, N = map(int, input().split())
box = [list(map(int, input().split())) for _ in range(N)]

# 초기 토마토 위치(시작점) 설정
queue = deque()
for y in range(N):
    for x in range(M):
        if box[y][x] == 1:
            queue.append((x, y))

# BFS로 토마토 익히기
while queue:
    x, y = queue.popleft()
    for dx, dy in direction:
        nx, ny = x + dx, y + dy
        if 0 <= nx < M and 0 <= ny < N and box[ny][nx] == 0:
            box[ny][nx] = box[y][x] + 1
            queue.append((nx, ny))

# 모든 토마토가 익었는지 확인
max_days = 0
for row in box:
    for tomato in row:
        if tomato == 0:  # 익지 않은 토마토가 있다면
            print(-1)
            sys.exit(0)
        max_days = max(max_days, tomato)

# 처음 시작을 1로 했기 때문에 1을 빼줌
print(max_days - 1)
