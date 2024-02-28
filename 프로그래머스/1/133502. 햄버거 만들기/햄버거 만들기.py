def solution(ingredient):
    answer = 0
    ## 빵 야채 고기 빵
    ## 1   2   3   1
    hamberger = [1,2,3,1]
    stack = []
    for i in range(len(ingredient)):
        stack.append(ingredient[i])
        if stack[-4:] == hamberger:
            for i in range(4):
                stack.pop()
            answer+=1
    return answer