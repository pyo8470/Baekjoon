Chess = list(map(int,input().split()))
Correct = [1,1,2,2,2,8]

for i in range(len(Chess)):
    print(Correct[i]-Chess[i],end=" ")
