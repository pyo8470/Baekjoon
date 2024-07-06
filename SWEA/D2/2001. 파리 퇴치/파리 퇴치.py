
for _ in range(1,int(input())+1):
    N,M = map(int,(input().split()))
    Board = [list(map(int,input().split())) for i in range(N)]
    answer = 0
    for y in range(N-M+1):
        for x in range(N-M+1):
            count = sum(Board[ny][nx] for ny in range(y,y+M) for nx in range(x,x+M))
            answer = max(count,answer)
    print(f'#{_} {answer}')