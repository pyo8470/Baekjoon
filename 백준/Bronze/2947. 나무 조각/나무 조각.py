import sys
input = sys.stdin.readline

block = list(map(int,input().split()))
def sort(i):
    if block[i] > block[i+1]:
        tmp = block[i]
        block[i] = block[i+1]
        block[i+1] = tmp  
        print(*block)
while block != [1,2,3,4,5]:
    for i in range(4):
        sort(i)
