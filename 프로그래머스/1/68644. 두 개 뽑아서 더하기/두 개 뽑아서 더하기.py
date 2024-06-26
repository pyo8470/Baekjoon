def solution(numbers):
    from itertools import combinations
    answer = set()
    n = len(numbers)
    
    # 모든 부분집합의 합을 구함
    comb = combinations(numbers, 2)
    for subset in comb:
        answer.add(sum(subset))
    
    return sorted(answer)  # 정렬된 리스트로 반환