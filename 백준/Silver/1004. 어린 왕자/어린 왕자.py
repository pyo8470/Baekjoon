## 어린왕자 수학 기계학

## 행성계 간의 이동을 피해야한다
## 행성계 진입/이탈 최소화

## 테스트케이스
for i in range(int(input())):
    count = 0
    ## 시작, 도착 지점
    x1,y1,x2,y2 = map(int,input().split())
    ## 행성의 개수
    n = int(input())
    for i in range(n):
        ## 행성의 위치와 반지름
        cx,cy,r = map(int,input().split())
        ## 시작점과의 거리
        dis_start = (cx-x1)**2 + (cy-y1)**2
        ## 도착점과의 거리
        dis_end = (cx-x2)**2 + (cy-y2)**2
        r = r**2
        ## 딱히 최단 거리를 구하는 문제가 아니다

        ### 케이스 1 : 시작점, 도착점이 모두 하나의 행성계에 있는 경우
        if dis_start < r and dis_end < r:
            continue
        ## 케이스 2 : 둘 다 똑같은 항성계가 아니라면
        ## 시작점이 내부에 있을 때
        elif r > dis_start :
            count+=1
        elif r > dis_end:
            count+=1
    print(count)