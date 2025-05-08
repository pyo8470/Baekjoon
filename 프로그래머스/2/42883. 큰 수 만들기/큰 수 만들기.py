def solution(number, k):
    answer = []
    
    stack = []
    length = len(number)-k
    for i in number:
        while stack and stack[-1] < i and k>0:
            stack.pop()
            k-=1
        stack.append(i)
        
    return ''.join(stack[:length])