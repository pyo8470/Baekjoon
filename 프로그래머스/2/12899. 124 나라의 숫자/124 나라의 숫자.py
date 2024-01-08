def solution(n):
    dic = {1: '1', 2: '2', 3: '4'}  # 0일 때 '4'로 변경
    answer = ''
    
    while n > 0:
        a = n % 3
        if a == 0:
            a = 3
            n -= 1  # 몫을 1 감소
        answer = dic[a] + answer
        n //= 3
    return answer