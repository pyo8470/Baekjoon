import sys
input = sys.stdin.readline

N,M = map(int,input().split())
woods = list(map(int,input().split()))
top = max(woods)
bottom = 0
answer = 0
while bottom<=top:
    cut = (top+bottom)//2
    total = 0
    for height in woods:
        if height > cut:
            total+=(height - cut)
    if total >= M :
        ## 더 자른 경우
        answer = max(cut,answer)
        bottom = cut + 1
    else:
        top = cut - 1
print(answer)