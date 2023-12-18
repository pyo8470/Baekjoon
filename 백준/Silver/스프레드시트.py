alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def column_number_to_name(n):
    result = ''
    while n :
        # 숫자를 26진수로 변환하여 열 이름을 생성
        k = (n - 1) % 26
        result = alpha[k] + result
        n = (n - 1) // 26
    
    return result

print(column_number_to_name(100000000))
