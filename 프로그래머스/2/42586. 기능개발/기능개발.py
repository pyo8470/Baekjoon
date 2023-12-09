import math
def solution(progresses, speeds):
    answer = []
    Days = []
    for i in range(len(progresses)):
        day = math.ceil((100-progresses[i])/speeds[i])
        Days.append(day)
    count = 1
    cur = Days[0]
    for i in Days[1:]:
        ## 뒤의 작업이 현재 작업보다 걸리는 일 수가 적거나 같은 경우
        if cur >= i:
            count+=1
        else:
            cur = i
            answer.append(count)
            count=1
    answer.append(count)
    return answer