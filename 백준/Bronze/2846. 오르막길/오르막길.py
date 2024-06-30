import sys
input = sys.stdin.readline

N = int(input())
height = list(map(int, input().split()))

last = height[0]
max_diff = 0
current_start = last

for i in range(1, N):
    if height[i] > last:
        max_diff = max(max_diff, height[i] - current_start)
    else:
        current_start = height[i]
    last = height[i]

print(max_diff)
