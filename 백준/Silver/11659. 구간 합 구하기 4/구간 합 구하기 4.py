import sys

N,M = map(int,sys.stdin.readline().split(" "))
Numbers = list(map(int,sys.stdin.readline().split(" ")))
SUM=[0 for i in range(N)]
for i in range(N):
    SUM[i]+=SUM[i-1]+Numbers[i]
for loop in range(M):
    i,j = map(int,sys.stdin.readline().split(" "))
    if i!= 1:
        print(SUM[j-1]-SUM[i-2])
    else:
        print(SUM[j-1])