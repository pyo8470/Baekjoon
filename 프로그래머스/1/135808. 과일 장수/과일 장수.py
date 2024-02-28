def solution(k, m, score):
    ## 가격 = 최소점수 * m 
    ## k = 최대 점수
    score.sort(reverse=True)
    result = []
    answer=0
    length = len(score)
    for i in range(0,(length - m)+1,m):
        if length - (i) < m:
            break
        else:
            result.append(score[i:i+m])
    for i in result:
        answer += min(i)*m
    return answer