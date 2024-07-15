import sys
input = sys.stdin.readline

N = int(input())
paper = [list(map(int,input().split())) for i in range(N)]
blue, white = 0,0

def div_con(x,y,n):
    global blue, white
    ## 같은색이 아니면 자름
    start = paper[y][x]
    for nx in range(x,x+n):
        for ny in range(y,y+n):
            if start != paper[ny][nx]:
                div_con(x,y,n//2)
                div_con(x+n//2,y,n//2)
                div_con(x,y+n//2,n//2)
                div_con(x+n//2,y+n//2,n//2)
                return
    ## 색이 같음
    if start == 1:
        blue += 1
    else:
        white +=1
div_con(0,0,N)
print(white)
print(blue)