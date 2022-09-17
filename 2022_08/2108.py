N = int(input())
x=[]
count =[0]*8001 # -4000 : 0, 4000: 8000, 0: 4000
for i in range (N):
    x.append(int(input()))
Avg=(sum(x)/N)
print(round(Avg))
# 평균



x.sort()           # 정렬
print(x[int(N/2)])    # 중앙값

# 최빈
for i in range(N):
    count[x[i]+4000]=count[x[i]+4000]+1
max_num=max(count)
max_Cnt=0
for i in range(0,8001):
    if max_Cnt==0 and count[i]==max_num:
        Final= i
        
        max_Cnt=max_Cnt+1
    elif max_Cnt==1 and count[i]==max_num :
        Final = i
        
        break
print(Final-4000)
Range=max(x)-min(x)      ## 범위
print(Range)    
    