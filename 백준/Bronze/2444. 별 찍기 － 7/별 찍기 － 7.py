k = int(input())

for i in range(k-1,-1,-1):
  print(" "*i + "*"*(2*(k-i)-1))
for i in range(1,k):
  print(" "*i + "*"*(2*(k-i)-1))