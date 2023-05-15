import copy
from collections import deque
T=int(input())
for i in range(T):
    queue = []
    N,M =map(int,input().split())
    # M = 초기 상태에서 몇번 째 문서인지 -> 순번
    priority = deque(list(map(int, input().split())))
    ## 위치 당겨짐
    ## 출력 분기
    ## 가장 크면
    count = 0 # 순번
    while(priority):
        max_pri=  max(priority)
        left = priority.popleft()
        M-=1   
        if(left == max_pri):
            count +=1
            ## 제거 -> queue 크기 감소
            if M<0:
                print(count)
                break
        ## 가장 크지 않으면
        else:
            #맨 뒤로 보냄
            priority.append(left)
            if(M<0):    #제일 앞에서 뽑힘
                M = len(priority)-1