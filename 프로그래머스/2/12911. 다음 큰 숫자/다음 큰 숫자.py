def get_binary(n):
    binary = ''
    if n == 0:
        return '0'
    while n:
        binary = str(n % 2) + binary
        n = n // 2
    return binary

def solution(n):
    answer = 0
    binary =  get_binary(n)
    count = binary.count('1')
    i = 1
    while True:
        next_bin = get_binary(n+i)
        if next_bin.count('1') == count:
            return n+i
        i+=1