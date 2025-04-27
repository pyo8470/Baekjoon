def solution(plans):
    answer = []
    
    def time_to_minute(time_str):
        h, m = map(int, time_str.split(':'))
        return h * 60 + m
    from collections import deque
    
    plans.sort(key=lambda x : x[1])
    plans = [(name, time_to_minute(start), int(playtime)) for name, start, playtime in plans]
    stack=[]
    
    for i in range(len(plans)):
        name, start, playtime = plans[i]
        
        ## 다음 과제 시작 시간
        next_time = plans[i+1][1] if i+1<len(plans) else float('inf')
        current_time = plans[i][1]
        stack.append([name,playtime])
        while stack:
            top_name, remaining_time = stack.pop()
            ## 끝낼 수 있는 경우
            if current_time + remaining_time <= next_time:
                current_time += remaining_time
                answer.append(top_name) 
            else:
                ## 못 끝내는 경우
                stack.append([top_name,remaining_time - (next_time-current_time)])
                break
                
    return answer