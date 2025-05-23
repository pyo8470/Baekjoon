
for t in range(int(input())):
    ## N번의 기회
    ## 1 1 2 3 5 8 13 21
    ## 1 -> x
    ## 2 -> 1/1 합 : 2 BA
    ## 3 -> 11/2 합 : 4 BBA
    ## 4 -> 합 : 7
    ## 5 -> 15/123합 6 BABBA 
    ## 6 -> 합 : 20 118/235 BBABBA
    ## 7 -> x
    ## 8 -> 합 : 54 12321/15813 ABBBAAAB
    f = ['impossible','BA','BBA']
    N = int(input())
    
    if N>3:
        for i in range(3,N):
            if i % 3 == 0:
                f.append('impossible')
            else:
                f.append(f[i-3] + 'BBA')
    print(f[N-1])