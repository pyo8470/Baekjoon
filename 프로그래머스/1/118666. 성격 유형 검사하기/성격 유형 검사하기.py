def solution(survey, choices):
    ## 1 : R ,T
    ## 2 : C, F
    ## 3 : J, M
    ## 4 : A, N
    answer= ''
    dic = {'R' : 0, 'T': 0,
           'C' : 0, 'F': 0,
           'J' : 0, 'M': 0,
           'A' : 0, 'N' :0}
    for i in range(len(survey)):
        first, second = survey[i][0],survey[i][1]
        point = choices[i]
        if point>4:
            dic[second] += point - 4
        else :
            dic[first] += 4-point
    
    mbti = list(dic.keys())
    
    for l,r in zip(mbti[::2],mbti[1::2]):
        if dic[l] < dic[r] :
            answer+=r
        else:
            answer+=l
    
    return answer