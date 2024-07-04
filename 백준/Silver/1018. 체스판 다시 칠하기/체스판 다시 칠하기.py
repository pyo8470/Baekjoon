import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [input().strip() for _ in range(N)]

# 두 가지 체스판 패턴
pattern1 = [['W', 'B'] * 4, ['B', 'W'] * 4] * 4
pattern2 = [['B', 'W'] * 4, ['W', 'B'] * 4] * 4

# 각 패턴과의 차이를 저장할 배열
diff1 = [[0] * M for _ in range(N)]
diff2 = [[0] * M for _ in range(N)]

# 차이 계산
for i in range(N):
    for j in range(M):
        if board[i][j] != pattern1[i % 8][j % 8]:
            diff1[i][j] = 1
        if board[i][j] != pattern2[i % 8][j % 8]:
            diff2[i][j] = 1

# 최소 변경 횟수 계산
min_changes = float('inf')

for i in range(N - 7):
    for j in range(M - 7):
        changes1 = sum(diff1[x][y] for x in range(i, i + 8) for y in range(j, j + 8))
        changes2 = sum(diff2[x][y] for x in range(i, i + 8) for y in range(j, j + 8))
        min_changes = min(min_changes, changes1, changes2)

print(min_changes)
