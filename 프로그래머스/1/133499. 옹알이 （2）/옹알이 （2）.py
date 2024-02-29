def solution(babbling):
    answer = 0
    say = ["aya", "ye", "woo", "ma"]
    
    for s in babbling:
        temp = ''
        final = ''
        for char in s:
            temp+=char
            if temp == final:
                break
            if temp in say:
                final = temp
                temp = ''
        if temp == '':
            answer+=1
            
    return answer