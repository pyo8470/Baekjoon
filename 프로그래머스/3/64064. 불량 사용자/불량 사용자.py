def solution(user_id, banned_id):

    result = set()
    visited = [False]*len(user_id)
    def is_match(user, banned):
        if len(user) != len(banned):
            return False
        for u, b in zip(user, banned):
            if b != '*' and u != b:
                return False
        return True
    
    
    def dfs(depth, path):
        if depth == len(banned_id):
            sorted_path = tuple(sorted(path))
            result.add(sorted_path)
            return
        
        for i in range(len(user_id)):
            if not visited[i] and is_match(user_id[i],banned_id[depth]):
                visited[i]=True
                dfs(depth+1 ,path + [user_id[i]])
                visited[i]=False
    
    dfs(0,[])
 
    return len(result)