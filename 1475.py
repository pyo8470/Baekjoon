# 숫자 9,6은 서로 같다고 본다
# 9 = 1 -> 1
# 9 = 2 -> 2/2 = 1 
# 9 = 3 -> 3/2 = 1
import math

a=input()
count=[0]*10
sum_of_6_9=0
for i in range(len(a)): 
  count[int(a[i])]+=1
sum_of_6_9=count[6]+count[9]
count[6]=math.ceil(sum_of_6_9/2)
count[9]=math.ceil(sum_of_6_9/2)
print(max(count))
