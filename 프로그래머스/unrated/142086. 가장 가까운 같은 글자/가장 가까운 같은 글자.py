def solution(s):
    answer = []
    alphabet = {}
    for i in range(len(s)):
        if s[i] not in alphabet.keys():
            answer.append(-1)
            alphabet[s[i]]=i
        else:
            answer.append(i-alphabet.get(s[i]))
            alphabet[s[i]]=i
    return answer