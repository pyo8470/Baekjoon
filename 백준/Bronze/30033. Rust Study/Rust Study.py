import sys
input = sys.stdin.readline

N = int(input())
plan = list(map(int,input().split()))
studied = list(map(int,input().split()))
count = 0
for p,s in zip(plan,studied):
    count +=1 if s-p >= 0 else 0
print(count)