def solution(n, l, r):
    answer = 0
    # 0 -> 1
    # 1 -> 11011
    # 2 -> 11011 11011 00000 11011 11011
                        ## 11 ~ 16
    # 3 -> 11011 11011 00000 11011 11011
                        ## 11 ~ 16
    #      11011 11011 00000 11011 11011
                        ## 11 + 25
    #      00000 00000 00000 00000 00000
            #
    #   -> 11011 11011 00000 11011 11011
    #   -> 11011 11011 00000 11011 11011
    dp=[1]*21
    for i in range(1,n+1):
        dp[i] = dp[i-1]*4
    
    
    def counts(n,left,right):
        if n==0:
            return 1
        
        length = 5**n
        unit = length//5
        
        answer = 0
        for i in range(5):
            start = i*unit
            end = start + unit-1
            
            if end<left or start>right:
                continue
                
            ## 0만있는 블럭들
            if i==2:
                continue
            
            
            ## 블럭 전부가 안에 포함
            if left <= start and end <= right:
                answer += dp[n-1]
            ## 한 쪽만 포함
            else:
                nl = max(0, left - start)
                nr = min(unit - 1, right - start)
                answer += counts(n - 1, nl, nr)
        return answer
    return counts(n,l-1,r-1)
    