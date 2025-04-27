from collections import deque

def solution(storage, requests):
    n = len(storage)
    m = len(storage[0])
    answer = 0
    directions = [(-1,0),(1,0),(0,-1),(0,1)]
    s = [['0' for i in range(m+2)] for i in range(n+2)]
    
    
    for x in range(m):
        for y in range(n):
            s[y+1][x+1] = storage[y][x]
    def lift(c):
        location = []
        for x in range(1,m+1):
            for y in range(1,n+1):
                if s[y][x] == c:
                    for dx,dy in directions:
                        nx,ny = x+dx,y+dy
                        if s[ny][nx] == '0':
                            location.append((x,y))
                            break
        for x,y in location:
            s[y][x] = '0'
            exposure(x,y)
                
    def crane(c):
        for x in range(1,m+1):
            for y in range(1,n+1):
                if s[y][x] == c:
                    s[y][x] = '1'
                    exposure(x,y)
    def exposure(x,y):
        expose = False
        for dx,dy in directions:
            nx,ny = x+dx, y+dy
            if s[ny][nx] == '0':
                s[y][x] = '0'
                expose = True
                break
        if expose:
            for dx,dy in directions:
                nx,ny = x+dx, y+dy
                if s[ny][nx] == '1':
                    s[y][x] = '0'
                    exposure(nx,ny)
    for R in requests:
        if len(R) == 1:
            lift(R[0])
        else:
            crane(R[0])
    
    answer = sum(1 for y in range(1,n+1) for x in range(1,m+1) if s[y][x] != '0' and s[y][x] != '1')
    return answer
