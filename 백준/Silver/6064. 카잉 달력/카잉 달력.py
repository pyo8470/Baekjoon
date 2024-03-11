import sys
input = sys.stdin.readline
T = int(input())
def find_K(M,N,x,y):
    K = y
    while K<=M*N:
        if (K-x)%M == 0 and (K-y)%N == 0:
            return K
        K+=N
    return -1
for _ in range(T):
    M,N,x,y = map(int,input().split())
    ## K = 10*a + 3  = 12*b + 9
    ## K - 3 = 10*a
            ## 10의 약수
    ## K - 9 = 12*b
            ## 12의 약수
    print(find_K(M,N,x,y))
    
