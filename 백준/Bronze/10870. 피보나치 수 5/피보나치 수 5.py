import sys

input = sys.stdin.readline

Fn = [0,1]
N = int(input())
if N <= 1 :
    print(Fn[N])
else:
    for i in range(2,N+1):
        Fn.append(Fn[i-1]+Fn[i-2])
    print(Fn[-1])