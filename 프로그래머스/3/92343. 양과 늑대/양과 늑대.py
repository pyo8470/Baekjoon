
import sys
sys.setrecursionlimit(10000000) 
def solution(info, edges):
    answer = []
    
    visited = [False for i in range(len(info))]
    def dfs(wolf,sheep):
        if sheep>wolf:
            answer.append(sheep)
        else:
            return
        
        ## 다시 돌아가도 양의 개수는 적립되어야함
        for s,e in edges:
            if visited[s] and not visited[e]: 
                visited[e] = True
                if info[e] == 1:
                    dfs(wolf+1,sheep)
                else:
                    dfs(wolf,sheep+1)
                visited[e] = False

    visited[0] = True
    dfs(0,1)
    return max(answer)