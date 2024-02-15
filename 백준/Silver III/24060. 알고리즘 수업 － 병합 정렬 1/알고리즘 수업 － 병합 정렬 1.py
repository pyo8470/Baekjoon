import sys
N, K =map(int,input().split())
A = list(map(int,sys.stdin.readline().split()))
ans  = []
## 원래 의사코드에 저장되는 수를 추가로 저장
def merge_sort(A):
    if len(A) <= 1:
        return A
    mid = (len(A)+1)//2
    firstHalf = merge_sort(A[:mid])
    secondHalf=merge_sort(A[mid:])
    
    tmp = []
    i = j = 0
    while i < len(firstHalf) and j < len(secondHalf):
        if firstHalf[i] <= secondHalf[j] :
            tmp.append(firstHalf[i])
            ans.append(firstHalf[i])
            i+=1
        else:
            tmp.append(secondHalf[j])
            ans.append(secondHalf[j])
            j+=1
    while i < len(firstHalf):
        tmp.append(firstHalf[i])
        ans.append(firstHalf[i])
        i+=1
    while j<len(secondHalf):
        tmp.append(secondHalf[j])
        ans.append(secondHalf[j])
        j+=1
    return tmp
merge_sort(A)

print(ans[K-1] if K<=len(ans) else -1)