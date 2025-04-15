def solution(n, s, a, b, fares):
    answer = 0
    INF = float('inf')
    
    distance = [[INF] * (n+1) for i in range(n+1)]
    for u,v,w in tuple(fares):
        distance[u][v] = w
        distance[v][u] = w
        
    for i in range(n+1):
        ## 자기 자신의 거리
        distance[i][i] = 0
    def floydWarshall():
        ## 경유 -> 출발 -> 도착
        for k in range(1,n+1):
            for i in range(1,n+1):
                for j in range(1,n+1):
                    if distance[i][k] != INF and distance[k][j] != INF:
                        distance[i][j] = min(distance[i][j],distance[i][k] + distance[k][j])
        
    floydWarshall()
    answer = INF
    ## s->k k->a k->b
    for k in range(1,n+1):
        answer = min(answer,distance[s][k] + distance[k][a] + distance[k][b])
    
    return answer