def solution(price, money, count):
    ## 등차수열 합 공식
    answer = count*(price+price*count)/2
    return max(0,answer-money)