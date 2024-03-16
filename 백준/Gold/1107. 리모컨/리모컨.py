import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
broken = list(map(int,input().split()))
broken_dic = {i: True if i in broken else False for i in range(10)}

min_count = abs(100-N)

for n in range(1000001):
    num = str(n)
    
    count = 0
    for i in num:
        count += 1
        ## 고장난 버튼인 경우
        if broken_dic[int(i)]:
            break
        ## 고장난거 없이 잘 온 경우
        elif count == len(num):
            min_count = min(min_count,abs(n-N)+count)
print(min_count)
            