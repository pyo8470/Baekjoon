N , M = map(int,input().split())
Board = []
for i in range(N):
    Board.append((input()))

count = []
## 두가지 경우로 나뉜다
## 시작 색이 B,W인 경우
for y in range(N-7):
    for x in range(M-7):
        startIsBlack = 0
        startIsWhite = 0
        for a in range(x,x+8):
            for b in range(y,y+8):
                ## 짝수 -> 같은 색이어야함
                if (a+b)%2 == 0:
                    if Board[b][a] == 'B':
                        startIsWhite += 1
                    else:
                        startIsBlack +=1
                ## 홀수 -> 다른 색이어야함
                else:
                    if Board[b][a] == 'B':
                        startIsBlack += 1
                    else:
                        startIsWhite +=1
        count.append(min(startIsWhite,startIsBlack))
print(min(count))