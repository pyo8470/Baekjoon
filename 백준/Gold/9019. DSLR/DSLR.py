import sys
input = sys.stdin.readline
from collections import deque
def calculation(num,C):
    if C == 'D':
        num = (num*2)%10000
    elif C == 'S':
        num = (num - 1)%10000
    elif C == 'L':
        num = num // 1000 + (num % 1000)*10
    elif C == 'R':
        num = (num%10)*1000 + (num//10)
    return num
cal = ['D','S','L','R']

def bfs(start,target):
    
    q = deque([(start, '')])
    while q:
        current,operation = q.popleft()
        visited[current] = True
        if current == target:
            return operation
        for i in cal:
            next_num = calculation(current,i)
            if not visited[next_num]:
                visited[next_num] = True
                q.append((next_num,operation+i))
for _ in range(int(input())):
    A,B = map(int,input().split())
    visited = [False for i in range(10001)]
    result = []
    print(bfs(A,B))
