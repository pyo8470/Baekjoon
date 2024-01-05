def solution(phone_book):
    
    ## 접두어 인 경우
    s = set()
    phone_book.sort()
    s.add(phone_book[0])
    for i in phone_book[1:]:
        number = ''
        for c in i:
            number+=c
            if number in s:
                return False
        s.add(i)
    answer = True
    return answer