def solution(number):
    answer = 0
    
    length = len(number)
    
    for a in range(length):
        for b in range(a+1,length):
            for c in range(b+1, length):
                if number[a] + number[b] + number[c] == 0 :
                    answer+=1
    return answer