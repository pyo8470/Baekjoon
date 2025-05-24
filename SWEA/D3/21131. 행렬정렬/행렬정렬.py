
for t in range(int(input())):
    
    N = int(input())
    
    A = [list(map(int,input().split())) for i in range(N)]
    
    B = [False] * N
    for i in range(N):
        if A[0][i] == i+1:
            B[i] = True
    answer=0
    for i in range(N-1,0,-1):
        if B[i]:
            continue
        else:
            answer+=1
            for j in range(i+1):
                B[j] = not B[j]
    print(answer)