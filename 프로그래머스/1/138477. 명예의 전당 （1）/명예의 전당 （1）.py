
def solution(k, score):
    
    honor = []
    answer = []
    for sc in score[:k]:
        honor.append(sc)
        honor.sort()
        answer.append(honor[0])
    for sc in score[k:]:
        honor.append(sc)
        honor.sort()
        honor.pop(0)
        answer.append(honor[0])
    return answer