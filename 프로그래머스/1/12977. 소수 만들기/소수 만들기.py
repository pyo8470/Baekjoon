import math
def solution(nums):
    # 소수는 1과 자기 자신으로만 나뉜다
    length= len(nums)
    allNum = []
    for i in range(0,length):
        for j in range(i+1,length):
            for p in range(j+1,length):
                allNum.append(nums[i]+nums[j]+nums[p])
    answer = len(allNum)
    for num in allNum:
        for i in range(2,int(math.sqrt(num))+1):
            if num % i == 0:
                answer-=1
                break
    return answer