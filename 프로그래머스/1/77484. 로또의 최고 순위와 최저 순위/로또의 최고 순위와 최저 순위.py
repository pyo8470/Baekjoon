def solution(lottos, win_nums):
    Rank=[6,6,5,4,3,2,1]
    zeroCount = lottos.count(0)
    Count = 0
    for i in lottos:
        if i in win_nums:
            Count+=1
    return [Rank[Count+zeroCount],Rank[Count]]