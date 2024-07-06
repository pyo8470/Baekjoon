def dfs(V):
    visited[V]=1
    for a in Network[V]:
        if(visited[a] == 0) : ## 방문했던 노드가 아니면
                            # 방문했던 노드라면 중복탐색이 or 무한루프 될 수 있기 때문()
                            ## 그 노드 안에서 탐색
            dfs(a)



N = int(input())
N_Pair = int(input())
visited = [0]*(N)
Network=[[] for row in range(N)]

for i in range(N_Pair):
    A,B = map(int,input().split())
    Network[A-1]+=[B-1]
    Network[B-1]+=[A-1]
dfs(0)
print(sum(visited)-1) # 1번을 제외한 수 -> -1

