def solution(arr, queries):
    for query in queries:
        # arr[i]의 값
        temp = arr[query[0]]
        # i에 j 넣기
        arr[query[0]] = arr[query[1]]
        # j에 i 넣기
        arr[query[1]] = temp
    return arr;