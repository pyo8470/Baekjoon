import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))
x = int(input())
A.sort()
i,j = 0,N-1
answer = 0
while i < j:
    total = A[i] + A[j]
    if x == total:
        answer+=1
        i+=1; j-=1
    elif x > total:
        i += 1
    else :
        j-=1
print(answer)