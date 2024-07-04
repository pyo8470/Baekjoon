import sys
input = sys.stdin.readline

N = int(input())
times = [list(map(int,input().split())) for i in range(N)]

times.sort(key = lambda x : (x[1],x[0]))
# print(times)

result = [times[0]]
for i in range(1,N):
    start = times[i][0]
    if result[-1][1] <= start:
        result.append(times[i])
print(len(result))