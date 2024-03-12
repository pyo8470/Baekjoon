import sys
from collections import deque
input = sys.stdin.readline
for _ in range(int(input())):
    N = int(input())
    people = [list(map(int,input().split())) for _ in range(N)]
    count = 1
    people.sort()
    ## 2차는 무조건 높아야함
    max = people[0][1]
    for i in range(1,N):
        if max > people[i][1]:
            count+=1
            ## [1,4] 뽑고, [4,1]
            max = people[i][1]
    print(count)