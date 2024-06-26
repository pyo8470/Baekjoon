def solution(left, right):
    odd = []
    even = []
    for num in range(left,right+1):
        count = 0
        for i in range(1,num//2+1):
            if num % i == 0:
                count+=1
        count+=1
        if count%2 == 0 :
            even.append(num)
        else:
            odd.append(num)
    return sum(even)-sum(odd)