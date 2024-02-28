def solution(number, limit, power):
    ## 약수 개수 == 공격력
    ## 개수 초과 -> power 사용
    result= [1]
    import math
    for i in range(2,number+1):
        count= 0
        for j in range(1,int(math.sqrt(i)+1)):
            if i%j == 0:
                count+=1
                if j**2 != i:
                    count+=1
        if count > limit:
            result.append(power)
        else:
            result.append(count)
    return sum(result)