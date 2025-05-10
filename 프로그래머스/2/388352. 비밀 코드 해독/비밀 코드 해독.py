from itertools import combinations

def solution(n, q, ans):
    answer = 0
    
    def compare(a, b):
        return len(a & b)
    
    all_comb = combinations(range(1, n + 1), 5)
    for comb in all_comb:
        flag = True
        comb_set = set(comb)
        for i in range(len(q)):
           
            count = compare(comb_set, set(q[i]))
            # print(count)
            if count != ans[i]:
                flag = False
                break
        if flag:
            answer += 1  # 조건을 만족하는 조합만 카운팅
    
    return answer
