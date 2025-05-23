
for t in range(int(input())):
    N = int(input())
    
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    
    selected = [False] * (N + 1)  # 1-based index
    result = [''] * (N + 1)  # 결과를 저장할 리스트
    A_idx = 0
    B_idx = 0
    for i in range(N):
        team = i%2
        if team == 0:
            while selected[A[A_idx]]:
                A_idx+=1
            chosen = A[A_idx]
            selected[chosen] = True
            result[chosen] = 'A'
        else:
            while selected[B[B_idx]]:
                B_idx+=1
            selected[B[B_idx]] = True
            result[B[B_idx]] = 'B'
    print("".join(result))

