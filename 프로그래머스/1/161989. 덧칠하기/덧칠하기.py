def solution(n, m, section):
    answer = 1
    start = section[0]
    for s in section:
        if start + m - 1 < s :
            start = s
            answer+=1
    return answer