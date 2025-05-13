def solution(n):
    answer = 0
    ## 닫힌 괄호 
    ## dp
    def dfs():
        result = []
        stack = [('(',1,0)]
        while stack:
            
            current, left,right=stack.pop()
            
            if left == n and right == n:
                result.append(current)
            
            if left < n:
                stack.append([current+'(',left+1,right])
            if right < left:
                stack.append([current+')',left,right+1])
        return result
    return len(dfs())