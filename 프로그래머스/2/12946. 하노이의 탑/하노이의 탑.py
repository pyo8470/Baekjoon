## 
def solution(n):
    answer = []
    def hanoi(src,trg,mid,n):
        if n == 1:
            ## n이 1인 경우
            answer.append([src,trg])
        else:
            ## n-1개를 출발 -> 중간으로 옮기는 것
            hanoi(src,mid,trg,n-1)
            ## n번째를 출발 -> 마지막
            hanoi(src,trg,mid,1)
            ## n-1번째를 중간 -> 마지막
            hanoi(mid,trg,src,n-1)
    hanoi(1,3,2,n)
    return answer