import sys
input = sys.stdin.readline

def combination(depth,idx):
    if depth == M:
        print(*answer)
        return
    for i in range(idx,N):
        if not check[i]:
            check[i] = 1
            answer[depth] = nums[i]
            combination(depth+1,i+1)
            ## 수열 만들고 옴
            check[i] = 0

N,M = map(int,input().split())
nums = sorted(list(map(int,input().split())))
check = [0]*N
answer = [0]*M
combination(0,0)