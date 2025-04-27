from functools import lru_cache
def solution(info, n, m):
    INF = float('inf')
    answer = INF
    
    visited = dict()
    
    def dfs(A,B,depth):
        nonlocal answer
        if A>=n or B>=m:
            return
        if A>=answer:
            return
        if depth == len(info):
            answer = min(A,answer)
            return
        if (A,B,depth) in visited:
            return
        
        visited[(A,B,depth)] = True
        a_trace, b_trace = info[depth]
        
        dfs(A+a_trace,B,depth+1)
        dfs(A,B + b_trace,depth+1)
        
    dfs(0,0,0)
    return answer if answer!=INF else -1