N = int(input())
papers = []
for i in range(N):
    papers.append(list(map(int,input().split())))
blue,white = 0,0

def solution(x,y,N):
    start_color = papers[y][x]
    for i in range(x, x+N):
        for j in range(y, y+N):
            ## 색이 같지 않을 경우 분할
            if start_color != papers[j][i]:
                solution(x,y,N//2)
                solution(x+N//2,y,N//2)
                solution(x,y+N//2,N//2)
                solution(x+N//2,y+N//2,N//2)
                return
    ## 색이 같은 경우
    if start_color == 1:
        global blue
        blue += 1
    else:
        global white
        white += 1
    
solution(0,0,N)
print(white)
print(blue)