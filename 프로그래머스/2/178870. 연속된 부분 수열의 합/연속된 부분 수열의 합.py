def solution(sequence, k):
    answer = []
    
    sum_seq = [i for i in sequence]
    
    length = len(sequence)
    for i in range(1,length):
        sum_seq[i] += sum_seq[i-1]
    
    ## 투포인터
    e = 0
    _sum = 0
    minLength = float('inf')
    
    for s in range(length):
        while _sum < k and e<length:
            _sum = sum_seq[e] - (sum_seq[s-1] if s > 0 else 0)
            e+=1
        if _sum == k:
            if e-s < minLength:
                minLength = e-s
                answer=[s,e-1]
        _sum -= sequence[s]
    return answer