def solution(participant, completion):
    answer = ''
    part = {}
    for a in participant:
        part[a] = part[a] + 1 if a in part else 1
    for k in completion:
        part[k] -=1
    for key,value in part.items():
        if value != 0 :
            answer=key
    return answer
