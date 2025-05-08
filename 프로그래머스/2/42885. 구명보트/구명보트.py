def solution(people, limit):
    answer = 0
    people.sort()
    
    ## 투포인터
    i = 0
    j = len(people)-1
    
    ## 무거운 사람을 먼저 태우는게 효과적
    while i<=j:
        ### 무게 제한에 걸리지 않는 경우
        if people[i]+people[j] <= limit:
            ## 가벼운 사람을 태운다.
            i+=1
        ## 무거운 사람은 일단 태우고 본다.
        j-=1
        answer+=1
    
    ## 무게 적은사람부터 태워보자
    ## 이 코드는 가장 적은사람 + 가장 많은 사람을 태우는 경우를 아예 무시한다.
    # curW = 0
    # onBoat = 0
    # for i in range(len(people)):
    #     if curW + people[i] <= limit and onBoat<2:
    #         curW+=people[i]
    #         onBoat+=1
    #     ## 배 갈아야 함
    #     else:
    #         curW = people[i]
    #         onBoat = 1
    #         answer+=1
    return answer