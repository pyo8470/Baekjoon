number = '0123456789'
import math
def change(num,binary):
    result = ""
    if num == 0:
        return "0"

    while num > 0:
        result = str(num % binary) + result
        num //= binary

    return result
def solution(n, k):
    answer = 0
    k_number = change(n,k)
    numbers = []
    start_index = 0
    for i, digit in enumerate(k_number):
        if digit == '0':
            if start_index != i:
                numbers.append(k_number[start_index:i])
            start_index = i + 1

    numbers.append(k_number[start_index:])

    for s in numbers:
        if s and s != '1' and all(int(s) % i != 0 for i in range(2, int(math.sqrt(int(s))) + 1)):
            answer += 1
    print(numbers)
    return answer