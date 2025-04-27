from collections import deque

def solution(board):
    directions= [(0,-1), (0,1), (1,0), (-1,0)]
    n = len(board)
    m = len(board[0])
    answer = []
    
    def bfs():
        start = (0,0)
        goal = (0,0)
        for y in range(n):
            for x in range(m):
                if board[y][x] == 'R':
                    start = (x, y)
                if board[y][x] == 'G':
                    goal = (x, y)
        
        dq = deque()
        dq.append((start[0], start[1], 0))  # (x, y, 이동횟수)
        visited = [[False for _ in range(m)] for _ in range(n)]
        visited[start[1]][start[0]] = True
        
        while dq:
            x, y, count = dq.popleft()
            
            if (x, y) == goal:
                answer.append(count)
                return
            
            for dx, dy in directions:
                nx, ny = x, y
                while True:
                    tx, ty = nx + dx, ny + dy
                    if 0 <= tx < m and 0 <= ty < n and board[ty][tx] != 'D':
                        nx, ny = tx, ty
                    else:
                        break

                if not visited[ny][nx]:
                    visited[ny][nx] = True
                    dq.append((nx, ny, count + 1))
    
    bfs()
    return min(answer) if answer else -1
