N,K=map(int,input().split())
Q=[0]*N
count=1
Q[K-1]=1
index=K-1
Series=[K]
while(count!=N):
  loopcount=0
  while(loopcount!=K):
    index+=1
    if index==N:
      index=0
    if Q[index]!=1:
      loopcount+=1
  if Q[index]==0:
    Q[index]+=1
  count+=1
  Series.append(index+1)
print('<',end="")
for k in range(N):
  if k==N-1:
    print(Series[k],end="")
  else :
    print(Series[k],', ',end="")
print('>',)

###################### 여러가지 테케를 돌려봤으나 왜 안되는지 모름 
