for t in range(int(input())):
    L,R = map(int,input().split())
    
    ## X개 세트
    # N//X 개의 묶음 세트 + N%X만큼의 단제품
    # N%X >= X/2-> 더 구매
    
    
    ## X가 충분히 커야한다(R보다는)
    if L*2 > R:
        print('yes')
    else:
        print('no')