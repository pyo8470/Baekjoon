N=int(input())
people=[]
count =N  ## 우선순위
for i in range(N):
    x,y=input().split()
    x=int(x)
    people.append([x,y,count])
    print(count)

people.sort(key = lambda x : (x[0],x[2])) ## 나이, 순번

for i in range(N):
    print(people[i][0],people[i][1])