def solution(n, lost, reserve):
    ## 자신이 잃어버리고 추가로 가져온 경우 제거
    LOST = list(set(lost) - set(reserve))
    REST= list(set(reserve) - set(lost))
    answer =  n - len(LOST)
    for L in LOST:
        for R in REST:
            if R+1 == L:
                answer+=1
                REST.remove(R)
                break
            elif R-1 == L:
                answer+=1
                REST.remove(R)
    return answer