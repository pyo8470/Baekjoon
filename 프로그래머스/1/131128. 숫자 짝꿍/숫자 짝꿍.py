def solution(X, Y):
    answer = ''
    from collections import Counter
    arr = []
    A = Counter(X)
    B = Counter(Y)
    for k in A.keys():
        if k in B.keys():
            arr.append((int(k),min(A[k],B[k])))
    if len(arr) == 0:
        return '-1'
    if len(arr) == 1 and arr[0][0] == 0 :
        return '0'
    arr.sort(reverse=True)
    for d in arr:
        for i in range(d[1]):
            answer+=str(d[0])
    return answer