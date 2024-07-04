import sys
input = sys.stdin.readline

N,K = map(int,input().split())


A = list(map(int,input().split()))
answer = [sum(A[:K])] 
for i in range(N-K):
    answer.append(answer[i] - A[i]+A[K+i])
print(max(answer))