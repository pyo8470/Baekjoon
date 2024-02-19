n = int(input())
import sys
stack,result = [], []
## 실패 조건이 무엇일까
## 1 2 5 3 4 -> 1 ,2 정상 5 스택 3 정상 4 스택 -> 
countNum = 1
for i in range(n):
    num = int(sys.stdin.readline())
    ## 스택 쌓기
    while countNum <= num :
        stack.append(countNum)
        result.append('+')
        countNum+=1

    
    ## 스택에서 빼기
    if stack[-1] == num:
        stack.pop()
        result.append('-')
    ## top이 맞지 않은 순간 실패
    else :
        print('NO')
        exit()   
print('\n'.join(result))