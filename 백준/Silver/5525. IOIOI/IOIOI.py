import sys
N = int(input())
M = int(input())
S = sys.stdin.readline()
Pn = 'I'+('OI'*N)
count =0
i=0
while i<M-2*N:
    if S[i] == 'I' and S[i:i+2*N+1] == Pn:
        count+=1
        # 이미 패턴 발견 -> 다음 검사
        i+=2
    else:
        i+=1
print(count)