import sys
from collections import deque
input = sys.stdin.readline
for _ in range(int(input())):
    N = int(input())
    people = [0 for i in range(N+1)]
    for k in range(N):
        a,b =map(int,input().split())
        ## 1차 기준 정렬 되어있는 거임
        people[a] =b 
    count = 1
    ## 2차는 무조건 높아야함
    max = people[1]
    for i in range(2,N+1):
        if max > people[i]:
            count+=1
            ## [1,4] 뽑고, [4,1]
            max = people[i]
    print(count)