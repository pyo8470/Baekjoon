import math
def solution(k, d):
    answer = 0
    for x in range(0,d+1,k):
        ## k를 나누는이유는 간격
        yCount = int(math.sqrt(d**2 - x**2))//k
        answer +=yCount+1 ## y좌표가 0인 경우도 포함
    return answer
