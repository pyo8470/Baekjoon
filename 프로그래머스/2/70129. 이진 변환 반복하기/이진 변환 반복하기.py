def binary(n):
    s = bin(n)
    return s[2:]
def solution(s):
    answer = [0,0]
    binary(4)
    while s != '1':
        zeroCount = s.count('0')
        length = len(s) - zeroCount
        s = binary(length)
        answer[0] += 1; answer[1]+=zeroCount
    return answer