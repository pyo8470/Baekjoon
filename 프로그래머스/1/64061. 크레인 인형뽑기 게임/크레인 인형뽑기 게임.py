from collections import deque
def check(stack):
    if stack[-1] == stack[-2]:
        stack.pop()
        stack.pop()
        return True
    return False
def solution(board, moves):
    answer = 0
    stack = deque([])
    height = len(board)
    for k in moves:
        for i in range(height):
            ## 뽑은 인형
            doll = board[i][k-1]
            if doll != 0:
                ## 판 비워주기
                board[i][k-1] = 0
                stack.append(doll)
                if len(stack)>=2:
                    if check(stack):
                        answer+=2
                break
    return answer