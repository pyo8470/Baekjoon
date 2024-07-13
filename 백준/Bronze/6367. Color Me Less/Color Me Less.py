import sys
input = sys.stdin.readline

RGB_table = [list(map(int,input().split())) for i in range(16)]
while True:
    r,g,b = map(int,input().split())
    if r == -1 and g == -1 and b == -1:
        break
    distance = []
    for R,G,B in RGB_table:
        distance.append((R-r)**2 + (G-g)**2 + (B-b)**2)
    min_index = min(range(16), key = lambda i : distance[i])
    answer = RGB_table[min_index]
    print(f'({r},{g},{b}) maps to ({answer[0]},{answer[1]},{answer[2]})')