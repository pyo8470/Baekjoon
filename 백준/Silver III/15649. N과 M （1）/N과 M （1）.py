N,M = map(int,input().split())
arr = [i+1 for i in range(N)]

def permutation(arr, n):
    result = []
    if n == 0:
        return [[]]
    
    for i in range(len(arr)):
        elem = arr[i]
        for rest in permutation(arr[:i] + arr[i+1:], n - 1):
            result.append([elem] + rest)
    return result
    
for i in permutation(arr,M):
    print(" ".join(map(str, i)))
