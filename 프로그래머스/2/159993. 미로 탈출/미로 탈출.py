from collections import deque
direction = [(0,1),(1,0),(0,-1),(-1,0)]
def bfs(x,y,maps,visited,w,h,des):
    
    q = deque([(x,y,0)])
    while q :
        x,y ,count= q.popleft()
        if maps[y][x] == des:
            return count
        for dx,dy in direction:
            nx,ny =  x+dx,y+dy
            if 0<=nx<w and 0<=ny<h:
                if maps[ny][nx] != 'X' and not visited[ny][nx]:
                    visited[ny][nx] = True
                    q.append((nx, ny, count + 1))
    return -1
        
def solution(maps):
    w = len(maps[0])
    h = len(maps)
    for x in range(w):
        for y in range(h):
            if maps[y][x] == 'S':
                visited = [[False]*w for i in range(h)]
                toLever = bfs(x,y,maps,visited,w,h,'L')
            if maps[y][x] == 'L':
                visited = [[False]*w for i in range(h)]
                toEnd = bfs(x,y,maps,visited,w,h,'E')
    if toLever != -1 and toEnd != -1:
        return toLever + toEnd
    return -1