## 6,9는 같다 -> 99 -> 6,9한 세트만 필요
import math
count=[0 for i in range(10)]

N=input()

for i in N:
    count[int(i)] +=1

## 6과 9는 같다고 침 -> 두개의 평균을 올림으로 구함
num_6=count[6]; num_9 = count[9]
avg=math.ceil((num_6+num_9)/2)
count[6]=avg;count[9] =avg 
print(max(count))