N,X=input().split()
N=int(N);X=int(X)
K=N*60+X
K=K-45
if K<0:
  K=K+1440
  print(int(K/60),K%60)
else :
  print(int(K/60),K%60)