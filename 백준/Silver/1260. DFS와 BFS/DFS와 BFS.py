def dfs(matrix:list[list[int]],visited : list[bool],vertex : int):
    if(visited[vertex] == True):
        return
    # 방문 하지 않았다
    visited[vertex] = True # 방문했다고 표기
    # 방문 했던 점이 아니면 경로에 추가
    print(vertex+1, end=" ")
    for index in range(len(matrix)):
        if matrix[vertex][index] == 1:
            dfs(matrix,visited,index)

def bfs(matrix:list[list[int]],visited : list[bool],vertex : int):
    # 큐 자료 구조 활용
    queue = []
    queue.append(vertex)
    visited[vertex] = True

    while(len(queue) != 0):
        ## 큐에 먼저 추가된 요소 뽑고 출력
        cur = queue.pop(0)
        print(cur+1,end=" ")
        ## 현재 레벨에서 방문하지 않았고 갈수 있는 모든 점
        for i in range(len(matrix)):
            if(matrix[cur][i] == 1 and (not visited[i])):
                queue.append(i)
                visited[i] = True
    return 

N,M,V=map(int, input().split())
Matrix = [[0 for j in range(N)]for i in range(N)]
for i in range(M):
    From, To = map(int,input().split())
    Matrix[From-1][To-1] = 1
    Matrix[To-1][From-1] = 1

visited = [False for i in range(N)]
dfs(Matrix,visited,V-1)
print()
visited = [False for i in range(N)]
bfs(Matrix,visited,V-1)