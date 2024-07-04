import sys
input = sys.stdin.readline
N = int(input())
frame = [list(map(int,input().split())) for i in range(N)]
answer = []
for person in frame:
    rank = 1
    for others in frame:
        if person[0] < others[0] and person[1]< others[1]:
            rank+=1
    answer.append(rank)
print(*answer)