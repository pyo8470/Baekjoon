def solve(depth,n):
    global result
    if depth == N//2:
        start,link = 0,0
        for i in range(N):
            for j in range(N):
                if visited[i] and visited[j]:
                    start += S[i][j]
                elif not visited[i] and not visited[j]:
                    link += S[i][j]
        result= min(result, abs(start-link))
        return result
    else:
        for i in range(n,N):
            if not visited[i]:
                visited[i] = True
                solve(depth+1,i+1)
                visited[i] = False
        
N = int(input())
S = [list(map(int,input().split())) for i in range(N)]
visited=[0]*N
result = float('inf')
solve(0,0)
print(result)