import sys
input = sys.stdin.readline

direction = [(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]
n = int(input())
mine = [list(map(str,input().strip())) for i in range(n)]
board = [list(map(str,input().strip())) for i in range(n)]
is_exploded = False
for y in range(n):
    for x in range(n):
        if board[y][x] == 'x':
            if mine[y][x] == '*':
                is_exploded = True
            count = 0
            for dx,dy in direction:
                nx,ny = x+dx, y+dy
                if 0<=nx<n and 0<=ny<n:
                    if mine[ny][nx] == '*':
                        count+=1
            board[y][x] = str(count)
if is_exploded:
    for y in range(n):
        for x in range(n):
            if mine[y][x] == '*':
                board[y][x] = '*'
for line in board:
    print(''.join(line))