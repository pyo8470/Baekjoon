import sys
input = sys.stdin.readline

def permutation(depth):
    if depth == M:
        print(*answer)
        return
    for i in range(N):
        if not check[i]:
            check[i] = 1
            answer[depth] = nums[i]
            permutation(depth+1)
            ## 수열 만들고 옴
            check[i] = 0

N,M = map(int,input().split())
nums = sorted(list(map(int,input().split())))
check = [0]*N
answer = [0]*M
permutation(0)