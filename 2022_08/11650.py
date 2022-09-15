N = int(input())
coor =[]
for i in range(N):
    x,y = map(int,input().split())
    coor.append([x,y])
    

coor.sort() 
for i in range(N):
    print(coor[i][0],coor[i][1])
