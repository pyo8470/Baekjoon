import sys
input = sys.stdin.readline
def dfs(n):
    visitied[n] = 1
    for v in graph[n]:
        if visitied[v] == 0:
            dfs(v)
N = int(input())
num_edge = int(input())
visitied = [0]*N
graph = [[] for i in range(N)]
for _ in range(num_edge):
    a,b = map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)
dfs(0)
print(sum(visitied[1:]))
