A=list(map(int,input().split()))
s = 0
for i in A:
    s+= (i**2)
print(s%10)