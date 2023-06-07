import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
Trees=list(map(int, sys.stdin.readline().rstrip().split()))

top= max(Trees)
bottom = 0
result = 0
while(bottom<top):
    cutting = (bottom+top) //2
    TotalHeight=0
    for i in Trees:
        currentH=i - cutting
        if currentH >= 0:
            TotalHeight += currentH
    if TotalHeight >= M:
        result = max(cutting,result)
        bottom = cutting + 1
    elif TotalHeight <M:
        top = cutting
print(result)