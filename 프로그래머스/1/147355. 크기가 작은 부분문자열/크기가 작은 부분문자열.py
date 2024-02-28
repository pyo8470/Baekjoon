def solution(t, p):
    length = len(p)
    answer = 0
    for i in range(len(t)-length+1):
        k = t[i:i+length]
        if int(k) <= int(p):
            answer+=1
    return answer