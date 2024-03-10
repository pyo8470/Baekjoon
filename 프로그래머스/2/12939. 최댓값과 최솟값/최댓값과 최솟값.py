def solution(s):
    k = list(map(int,s.split()))
    answer = ''
    answer += str(min(k)) + ' ' +str(max(k))
    return answer