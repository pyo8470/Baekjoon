from itertools import combinations, permutations
import math
N,M=map(int,(input().split()))
CARD=list(map(int,input().split()))

## 주어진 수 N개중 3개를 고르는 모든 경우
combination =list(combinations(CARD,3))
length=len(combination)
finish=0
## 모든 경우의 수에서 M보다 크지 않고 M에 가장 가까운 수를 구한다.
for i in range(length):
    temp = sum(combination[i])
    if temp <= M and temp>= finish:
        finish=temp

print(finish)


## 모든 조합을 찾아서 조건에 맞는 해를 구하는 문제
## combinations 함수 이용