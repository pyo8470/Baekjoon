def solution(l,r):
    answer=[]
    for i in range(l,r+1):
        k = str(i)
        count =0 
        for char in k :
            if char == '0' or char == '5' :
                count+=1
        if len(k) == count:
            answer.append(i)
    if len(answer) == 0 :
        answer= [-1]
    return(answer)