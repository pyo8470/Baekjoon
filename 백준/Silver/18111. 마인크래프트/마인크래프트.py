## 작업 종류 -> 제거(2초), or 블럭 깔기(1초)
import sys
N,M,B = map(int,input().split())

ground = [list(map(int,sys.stdin.readline().split())) for i in range(N)]
minH,maxH = min(min(ground)),max(max(ground))
minTime,finalH= int(1e9),0
for i in range(minH,maxH+1):
    setBlock = 0
    getBlock = 0
    for y in range(N):
        for x in range(M):
            ## (높음) -> 제거
            if ground[y][x] > i:
                getBlock += ground[y][x] - i
            ## 낮음 -> 깔기
            else:
                setBlock += i - ground[y][x]
    ## 박스 개수가 부족 했다면

    if getBlock + B < setBlock:
        continue
    time = getBlock*2 + setBlock
    if minTime >= time :
        minTime = time
        finalH = i
print(minTime,finalH)
            
            