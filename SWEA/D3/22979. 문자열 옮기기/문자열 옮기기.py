for t in range(int(input())):
    S = input().strip()
    K = int(input())
    commands = list(map(int,input().split()))

    ## 모든 명령의 합을 구한 다음, 나머지로 나누면
    ## 굳이 명령마다 연산할 필요가 없다
    x = sum(commands)%len(S)
    S = (S[x:] + S[:x])
    print(S)