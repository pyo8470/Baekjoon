import sys
input = sys.stdin.readline

N = int(input())
for i in range(1, N+1):
    num = sum(map(int,str(i)))
    Sum = num+i
    if Sum == N:
        print(i)
        break
    if i == N:
        print(0)