
for t in range(int(input())):
    S = input().strip()
    K = int(input())
    commands = list(map(int,input().split()))
    for x in commands:
        temp = ""
        if x == 0:
            continue
        else :
            x = x % len(S)
            temp = (S[x:] + S[:x])
            S = temp
    print(S)