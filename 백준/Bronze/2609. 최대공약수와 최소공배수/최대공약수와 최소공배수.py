N,K = map(int,input().split())

# 최대공약수
for i in range(min(N,K),0,-1):
    if N%i == 0 and K%i == 0:
        a=i
        print(i)
        break
# 최소공배수
print(N*K//a)