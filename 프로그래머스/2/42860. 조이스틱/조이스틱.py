def solution(name):
    answer = 0
    ## A B C D E F G H I J K L M
    ## N O P Q R S T U V W X Y Z
    length =len(name)
    start = 'A'*length
    ## 위 아래 왼, 다음
    
    ## 각자리에서 각자의 알파벳 만드는데 필요한 횟수
    count = [0]*length
    
    for i in range(length):
        distance = abs(ord(name[i]) - ord(start[i]))
        count[i] = 26-distance if distance > 12 else  distance
    
    answer = sum(count)
    
    min_move = length - 1
    
    for i in range(length):
        next_idx = i + 1
        ## 연속된 A의 길이
        while next_idx<length and count[next_idx] == 0:
            next_idx+=1
        ## 오른쪽으로 i만큼 갔다가 다시 왼쪽
        move_back = i + i + (length-next_idx)
        
        ## 
        move_all = i + (length-next_idx)*2
        min_move = min(move_all,move_back,min_move)
    
    return answer + min_move