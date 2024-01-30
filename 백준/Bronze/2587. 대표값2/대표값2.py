N = []
for i in range(5):
    N.append(int(input()))
N.sort()
print(sum(N)//5)
print(N[2])