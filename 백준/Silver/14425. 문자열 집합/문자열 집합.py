import sys
N, M = map(int, sys.stdin.readline().split())
S = set()
count=0
for i in range(N):
    S.add(sys.stdin.readline())
for i in range(M):
    word = sys.stdin.readline()
    if word in S:
        count+=1
print(count)