## 이분탐색
def solution(diffs, times, limit):
    def 시간계산(level):
        time_spend = 0
        for i in range(len(diffs)):
            diff, time_cur,time_prev = diffs[i], times[i],times[i-1]
            ## 난이도가 낮거나 같은 경우
            if level >= diff:
                time_spend += time_cur
            else:
                wrong_count = diff-level
                time_spend += (time_cur + time_prev)*wrong_count + time_cur
        return time_spend
    
    top =max(diffs); bottom = 1; 
    answer = 0 
    times.append(0)
    ## limit보다 높은 시간 -> level을 올려야함
    ## limit보다 낮은 시간 -> 일단 answer에 넣고 level 낯추기
    while bottom <=top :
        level = (top+bottom)//2 
        time_spend = 시간계산(level)
        if time_spend > limit:
            ## level 갱신
            bottom = level + 1
        else:
            answer = level
            top = level - 1
        
    return answer