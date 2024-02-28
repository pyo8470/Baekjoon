def solution(s, skip, index):
    answer = ''
    alpha = sorted(set('abcdefghijklmnopqrstuvwxyz')-set(skip))
    num = len(alpha)
    for c in s:
        answer += alpha[(alpha.index(c) + index) % num]
    return answer