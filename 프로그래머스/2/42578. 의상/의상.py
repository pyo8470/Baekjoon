def solution(clothes):
    k = {}
    answer = 1
    for cloth, kind in clothes:
        k[kind] = k.get(kind, 0) + 1
    for key,val in k.items() :
        answer*=(val+1)
    print(k)
    answer -=1
    return answer

