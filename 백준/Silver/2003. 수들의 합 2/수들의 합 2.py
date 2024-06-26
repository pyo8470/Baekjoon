import sys
input = sys.stdin.readline

N,M = map(int,input().split())


A = list(map(int,input().split()))
answer=0
left,right = 0, 1
while left<=right and right<=N:
    total = sum(A[left:right])
    if total < M:
        right+=1
    elif total > M:
        left +=1
    else:
        answer+=1
        right+=1
## 이것조차 최악의 경우 O(N^2)
# for i in range(N):
#     ## tmp가 M보다 커지면 뒤는 볼 필요가 없음
#     tmp = 0
#     for j in range(i,N):
#         tmp += A[j]
#         if tmp == M:
#             answer += 1         
#         if tmp>M:
#             break
            

## 시간 초과 알고리즘 O(N^2)
# for i in range(N):
#     for j in range(i,N):
#         if sum(A[i:j+1]) == M:
#             answer+=1
print(answer)
