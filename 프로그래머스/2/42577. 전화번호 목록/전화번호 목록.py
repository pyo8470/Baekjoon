def solution(phone_book):
    
    s = set()
    ## 짧은 것부터 넣어야 된다 -> 따라서 길이순 정렬
    phone_book.sort(key=len)
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