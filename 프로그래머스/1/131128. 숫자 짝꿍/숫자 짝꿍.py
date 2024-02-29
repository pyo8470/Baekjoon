def solution(X, Y):
    answer = ''
    XList = [0 for i in range(10)]
    YList = [0 for i in range(10)]
    for x in X:
        XList[int(x)] +=1
    for y in Y:
        YList[int(y)] +=1 
    final = [0 for i in range(10)]
    for i in range(10):
        final[i] = min(XList[i],YList[i])
    if sum(final) == 0:
        return '-1'
    if sum(final[1:]) == 0:
        return '0'
    for i in range(9,-1,-1):
        for j in range(final[i]):
            answer+=str(i)
    
    return answer