def solution(n):
    direction = [(1,0),(0,1),(-1,0),(0,-1)]  # 우, 하, 좌, 상
    answer = [[0]*n for _ in range(n)]
    
    x, y, d = 0, 0, 0
    for i in range(1, n**2 + 1):
        answer[y][x] = i
        dx, dy = direction[d]
        nx, ny = x + dx, y + dy
        
        if not (0 <= nx < n and 0 <= ny < n and answer[ny][nx] == 0):
            d = (d + 1) % 4  # 방향 전환
            dx, dy = direction[d]
            nx, ny = x + dx, y + dy  
        x, y = nx, ny

    return answer
