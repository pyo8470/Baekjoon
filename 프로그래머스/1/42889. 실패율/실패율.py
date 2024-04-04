def solution(N, stages):
    fail_dic = {}
    people = len(stages)
    for i in range(1,N+1):
        if people != 0:
            fail_num = stages.count(i)
            fail_dic[i] = fail_num/people
            people-=fail_num
        else:
            fail_dic[i] = 0
    answer =sorted(fail_dic.items(), key = lambda item: -item[1])
    return [pair[0] for pair in answer]