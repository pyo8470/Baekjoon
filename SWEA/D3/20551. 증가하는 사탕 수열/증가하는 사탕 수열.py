for t in range(int(input())):
    A = list(map(int,input().split()))

    answer = 0
    while A[1]>=A[2]:
        answer+=1
        A[1] -=1
    
    while A[0]>=A[1]:
        answer+=1
        A[0]-=1
    if min(A) <= 0:
        answer = -1
    print(f"#{t+1} {answer}")