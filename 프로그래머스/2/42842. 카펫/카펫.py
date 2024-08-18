def get_division(n):
    import math
    divisors = set()
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    return divisors

def solution(brown, yellow):
    n = brown + yellow
    divisors = list(get_division(n))
    divisors.sort()
    for row in divisors[:len(divisors)//2-1:-1]:
        col = n // row
        print(row,col)
        # 조건 없이 row와 col을 사용
        if (col - 2) * (row - 2) == yellow:
            return [row, col]
