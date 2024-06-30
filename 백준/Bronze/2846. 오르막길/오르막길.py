import sys
input = sys.stdin.readline
N = int(input())

height = list(map(int,input().split()))
last = height[0]
upstairs = []
current = []
for i in range(1,N):

    if last < height[i]:
        current.append(last)
        current.append(height[i])
    else:
        if current:
            upstairs.append(current)
        current=[]
    last = height[i]
if current:
    upstairs.append(current)
answer = 0
for i in upstairs:
    answer = max(answer,i[-1]-i[0])
print(answer)