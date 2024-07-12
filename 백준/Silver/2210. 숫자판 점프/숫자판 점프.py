import sys
input = sys.stdin.readline
direction = [(1,0),(-1,0),(0,1),(0,-1)]

def dfs(x,y,num):
    if len(num) == 6:
        nums.add(num)
        return
    for dx,dy in direction:
        nx,ny = x+dx,y+dy
        if 0 <= nx < 5 and 0 <= ny < 5:
            dfs(nx,ny,num + board[ny][nx])

board = list(input().split() for i in range(5))
nums = set()

for y in range(5):
    for x in range(5):
        dfs(x,y,board[y][x])
print(len(nums))