N = int(input())
a = dict()
Have = list(map(int,input().split()))
for num in Have:
    if num in a.keys():
        a[num]+=1
    else:
        a[num] =1
M= int(input())
Find = list(map(int,input().split()))
Result =[]
for num in Find:
    if num in a.keys():
        Result.append(a[num])
    else:
        Result.append(0)
for i in Result:
    print(i,end=" ")