def solution(targets):
    answer = 0
    targets.sort(key = lambda x: x[1])
    boundary = -1
    for s,e in targets:
        # print(s,e,boundary)
        if s >= boundary :
            # print("+",s,e,boundary)
            answer+=1
            boundary = e
            
    return answer
## 