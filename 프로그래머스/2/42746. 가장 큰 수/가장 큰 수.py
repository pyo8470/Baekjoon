def solution(numbers):
    answer = ''
    ## 세자리로 만들기
    
    ## 아스키 코드 값으로 비교함
    ## 첫자리부터
    ## 6 10 -> 666 101010 -> 6>1 -> 666>101010
    ## 3 30 -> 333 303033 -> 3 = 3 -> 3 > 0 -> 333 > 303030
    numbers.sort(key = lambda x : str(x)*3)
    answer = "".join(str(numbers[i]) for i in range(len(numbers)-1, -1, -1))
    
    return '0' if answer[0] == '0' else answer