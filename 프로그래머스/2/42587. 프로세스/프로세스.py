def solution(priorities, location):
    answer = 0
    PQ = [[i, priorities[i]] for i in range(len(priorities))]
    maxP = max(priorities)
    
    while True:
        [curL, curP] = PQ[0]
        PQ = PQ[1:]
        if curP == maxP:
            answer+=1
            maxP=0
            for node in PQ:
                if node[1] > maxP:
                    maxP = node[1]
            if curL==location:
                break
        else:
            PQ.append([curL,curP])

    return answer