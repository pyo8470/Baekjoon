import sys
from itertools import combinations
input = sys.stdin.readline
T=int(input())
def dist(a,b):
    return sum(1 for i, j in zip(a, b) if i != j)
for _ in range(T):
    N = int(input())
    mbti = list(map(str,input().split()))
    if N>=33:
        print(0)
    else:
        ans = float('inf')
        for combi in combinations(mbti, 3):
            count = sum(dist(a, b) for a, b in combinations(combi, 2))
            ans = min(ans, count)
        print(ans)
    
            
        