def solution(numbers):
    answer = [-1] * len(numbers)
    stack = [] ## 인덱스 저장
    for i in range(len(numbers)):
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
            
        stack.append(i)
        
    return answer