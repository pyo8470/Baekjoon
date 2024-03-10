def solution(s):
    answer = ''
    first = True
    for i in s:
        if i == ' ':
            first = True
            answer+=i
        else:
            if first :
                answer += i.upper() 
            else :
                answer += i.lower()
            first = False
            
    return answer