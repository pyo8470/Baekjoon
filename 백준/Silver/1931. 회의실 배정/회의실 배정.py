# 1931 회의실 배정
N=int(input())
K = []
for i in range(N):
    x,y=map(int,input().split())
    K.append([x,y])
K.sort(key = lambda x:x[0])
K.sort(key = lambda x:x[1])

# 마지막에 끝나는 시간이, 시작하는 시간과 작거나 같으면 된다
result = []
## 첫번째를 넣어주자
result.append(K[0])
for i in range(1,N):
    start =K[i][0]
    if result[-1][1] <= start:
        result.append(K[i])
print(len(result))