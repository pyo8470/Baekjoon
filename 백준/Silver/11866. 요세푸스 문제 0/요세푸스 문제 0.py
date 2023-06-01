N,K = map(int,input().split())

people = [i+1 for i in range(N)]
index = K-1
Result =[]
while True:
    turn = people.pop(index)
    Result.append(turn)
    if len(Result) == N:
        break
    index+=K-1
    length = len(people)
    while(index>=length):
        index = index-length
print("<",end='')
for i in range(len(Result)-1):
    print("%d, "%Result[i], end='')
print(Result[-1], end='')
print(">")