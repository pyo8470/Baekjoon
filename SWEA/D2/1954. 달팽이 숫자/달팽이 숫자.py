dx = [1,0,-1,0]
dy = [0,1,0,-1]
for i in range(1,int(input())+1):
    N = int(input())
    print(f'#{i}')
    x,y = 0,0
    dist = 0
    snail = [[0]*N for i in range(N)]
    for n in range(1,N**2+1):
        snail[y][x] = n
        y, x = y + dy[dist], x + dx[dist]
        ## 옳지 않은 방향인 경우
        if x<0 or y<0 or x>=N or y>=N or snail[y][x]:
            y ,x = y-dy[dist], x - dx[dist]
            dist = (dist+1)%4
            y, x = y + dy[dist], x + dx[dist]
    for row in snail:
        print(*row)