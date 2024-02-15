N = int(input())
import math
s = str(math.factorial(N))
count = 0
for i in reversed(s):
    if i != '0':
        break
    count +=1
print(count)
