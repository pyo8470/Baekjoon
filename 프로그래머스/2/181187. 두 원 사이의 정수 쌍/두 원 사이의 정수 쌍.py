def solution(r1, r2):
    answer = 0
    import math
    
    
    ## 1사분면에 대하여
    for x in range(1,r2+1):
        maxY = math.floor(math.sqrt(r2**2-x**2))
        minY = 0
        if x < r1:
            minY = math.ceil(math.sqrt(r1**2 - x**2))
        # print(maxY,minY)
        answer+=(maxY-minY+1)
        
    return (answer)*4