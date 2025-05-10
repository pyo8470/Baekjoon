def solution(maps):
    answer = []
    directions = [(-1,0),(1,0),(0,1),(0,-1)]
    lengthRow = len(maps)
    lengthCol = len(maps[0])
    maps = [list(row) for row in maps]
    def dfs(x,y):
        stack = [(x, y)]
        total = int(maps[y][x])
        maps[y][x] = 'X'  # 방문 처리
    
        while stack:
            x, y = stack.pop()
    
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
    
                if 0 <= nx < lengthCol and 0 <= ny < lengthRow:
                    if maps[ny][nx] != 'X':
                        total += int(maps[ny][nx])
                        maps[ny][nx] = 'X'
                        stack.append((nx, ny))
    
        return total

    for i in range(lengthRow):
        for j in range(lengthCol):
            if maps[i][j] != 'X':
                answer.append(dfs(j,i))
    
    answer.sort()
    return answer if answer else [-1]