import sys
def Cantorian(start,size):
    if size == 1:
        return
    for i in range(start + size//3,start+(size//3)*2):
        S[i] = " "
    ## 좌측 자르기
    Cantorian(start,size//3)
    ## 우측 자르기
    Cantorian(start+(size//3)*2,size//3)
while True:
    try:
        A = int(sys.stdin.readline().strip())
        S = ['-']*(3**A)
        Cantorian(0,3**A)
        print("".join(S))
    except:
        break
