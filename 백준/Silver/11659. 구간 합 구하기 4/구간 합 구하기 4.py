import sys
input = sys.stdin.readline

N,M = map(int,input().split())
A = list(map(int,input().split()))
total = [0]
for i in range(N):
    total.append(total[i] + A[i])
for _ in range(M):
    i, j = map(int,input().split())
    answer = total[j] - total[i-1]
    print(answer)