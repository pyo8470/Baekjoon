N = int(input())
x=[]
count =[0]*8001 # -4000 : 0, 4000: 8000, 0: 4000
for i in range (N):
    x.append(int(input()))
Avg=(sum(x)/N)
print(round(Avg))       # 평균


x=sorted(x)             # 정렬
print(x[round(N/2)])    # 중앙값
for i in range(N):
    count[x[i]+4000]=count[x[i]+4000]+1
tmp = max(count)
index_first=count.index(tmp)
count[index_first]=-1
if max(count)==tmp:
    index_second=count.index(max(count))
    print(index_second-4000)
else :
    print(index_first-4000)

Range=x[N-1]-x[0]       ## 범위
print(Range)    
    