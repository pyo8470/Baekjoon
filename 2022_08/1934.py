
import math

T = int(input())

for i in range(T):
    A,B=map(int,input().split())
    MAX_DIV=1
    temp=MAX_DIV
    while(1):
        if(A%temp == 0 and B%temp==0):
            MAX_DIV=temp
        temp+=1
        if(temp>max(A,B)):
            break
    print(int(A*B/MAX_DIV))
            


## 모든 조합을 찾아서 조건에 맞는 해를 구하는 문제
## combinations 함수 이용