import sys
input = sys.stdin.readline
from collections import Counter
N,M = map(int,input().split())
woods = Counter(map(int,input().split()))
top = max(woods)
bottom = 0
answer = 0
while bottom<=top:
    cut = (top+bottom)//2
    total = 0
    for height, count in woods.items():
        if height > cut:
            total+=(height - cut)*count
    if total >= M :
        ## 더 자른 경우
        answer = max(cut,answer)
        bottom = cut + 1
    else:
        top = cut - 1
print(answer)