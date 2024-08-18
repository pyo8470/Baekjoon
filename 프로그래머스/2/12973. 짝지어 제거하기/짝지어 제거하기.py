def solution(s):
    answer = -1
    stack = []
    for i in range(len(s)):
        stack.append(s[i])
        if len(stack) >= 2 and stack[-1] == stack[-2]:
            stack.pop()
            stack.pop()
    return 0 if len(stack) else 1