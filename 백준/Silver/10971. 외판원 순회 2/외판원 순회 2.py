import sys
input = sys.stdin.readline
answer = sys.maxsize
## 현재위치, 비용, 깊이
def travel(current,cost,depth):
    global answer
    ## 처음 도시로 가야함
    if depth == N:
        if W[current][0]:
            cost += W[current][0]
            answer = min(cost,answer)
            return
        else:
            return
    for next_city in range(N):
        if not visited[next_city] and W[current][next_city]:
            visited[next_city] = 1
            travel(next_city,cost+W[current][next_city],depth+1)
            visited[next_city] = 0
N = int(input())
visited = [0] * N; visited[0] = 1
W = [list(map(int,input().split())) for _ in range(N)]
travel(0,0,1)
print(answer)