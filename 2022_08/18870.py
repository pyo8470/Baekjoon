N=int(input())
num_list=list(map(int,input().split()))

num_sorted=sorted(list(set(num_list)))
## 딕셔너리 활용
coorzip={num_sorted[i] : i for i in range(len(num_sorted))}
## 좌표 : 압축
## key  : value

for i in num_list:
    print(coorzip[i],end=" ")
