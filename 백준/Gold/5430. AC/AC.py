import sys
input = sys.stdin.readline
from collections import deque
### R,D
for i in range(int(input())):
    p = input() + '0'
    n = int(input())
    arr = deque(input().rstrip()[1:-1].split(","))
    if n == 0:
        arr = deque()
    rev=0
    for command in p:
        ### 시간초과
        # if command == 'R':
        #     arr.reverse()
        if command == 'R':
            rev+=1
        else:
            if command == '0':
                if rev%2 == 1:
                    arr.reverse() 
                print('['+",".join(arr)+']')
            if command == 'D':
                if n == 0 :
                    print('error')
                    break
                else:
                    if rev%2 == 1:
                        arr.pop()
                    else:
                        arr.popleft()
                    n-=1
                        
            