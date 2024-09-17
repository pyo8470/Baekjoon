def time_to_solve(level, diff, time_cur, time_prev):
    # 숙련도가 난이도보다 높을 때
    if level >= diff:
        return time_cur
    # 숙련도가 난이도보다 낮을 때
    else:
        return (diff - level) * (time_cur + time_prev) + time_cur
    
def solution(diffs, times, limit):
    max_level, min_level = max(diffs), 1
    length = len(diffs)
    while min_level<max_level:
        mid_level = (min_level+max_level)//2
        total = 0
        ## answer부터 시작
        for i in range(length):
            if not i:
                prev = 0
            else:
                prev = times[i-1]
            total += time_to_solve(mid_level,diffs[i],times[i],prev)
            
        if total <= limit:
            max_level = mid_level
        # 제한 시간 내에 문제를 풀 수 없다면
        # 최솟값을 올려줍니다.
        else:
            min_level = mid_level + 1
    return min_level