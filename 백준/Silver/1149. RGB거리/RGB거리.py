import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

N = int (input())
S = [list(map(int,input().split())) for i in range(N)]

for i in range(1,N):
    S[i][0] += min(S[i-1][1],S[i-1][2])
    S[i][1] += min(S[i-1][0],S[i-1][2])
    S[i][2] += min(S[i-1][0],S[i-1][1])
print(min(S[N-1]))