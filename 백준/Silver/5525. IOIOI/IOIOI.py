import sys
N = int(input())
M = int(input())
S = list(sys.stdin.readline().rstrip())
Pn = 'I'+('OI'*N)
count =0
for i in range(M):
    if i < M-2*N and S[i] =='I':
        temp=S[i]
        for j in range(N):
            temp+=(S[i+2*j+1]+S[i+2*j+2])
        if(temp == Pn):
            count+=1
print(count)