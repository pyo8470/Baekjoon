def binary(n,num,s):
    x=num
    y = ''
    while x>0:
        y = str(x%2) + y
        x //=2
    if len(y) < n:
        y = '0'*(n-len(y)) + y
    return y

def solution(n, arr1, arr2):
    map1 = []
    map2 = []
    answer = []
    for i in arr1:
        map1.append(binary(n,i,''))
    for i in arr2:
        map2.append(binary(n,i,''))
    for a,b in zip(map1,map2):
        s=''
        for i in range(n):
            if a[i] == '0' and b[i] == '0':
                s += ' '
            else:
                s += '#'
        answer.append(s)
    return answer