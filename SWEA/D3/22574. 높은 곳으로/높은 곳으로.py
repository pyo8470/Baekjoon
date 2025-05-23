for t in range(int(input())):
    ## N번의 기회
    ## x층 -> i 번째 선택 [x,x+i] 구간에 위치
    ## P층 폭탄
    N,P = map(int,input().split())
    answer=0
    for i in range(1,N+1):
        answer+=i
        if answer == P:
            answer-=1
    print(answer)