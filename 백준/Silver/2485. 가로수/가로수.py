import sys
input = sys.stdin.readline

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

N = int(input())
trees = [int(input()) for _ in range(N)]

# 간격 계산
sub = [trees[i+1] - trees[i] for i in range(N-1)]

# 최대 공약수 계산
g = sub[0]
for i in range(1, N-1):
    g = gcd(g, sub[i])

# 필요한 나무의 수 계산
answer = sum((i // g - 1) for i in sub)
print(answer)
