import sys
from itertools import combinations
input = sys.stdin.readline
N,M = map(int,input().split())
L = list(i for i in range(1,N+1))
a = combinations(L,M)
for i in a:
    print(*i)