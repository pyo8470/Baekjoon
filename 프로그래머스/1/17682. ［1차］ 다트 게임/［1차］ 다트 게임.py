def solution(dartResult):
    answer = []
    ## S1 D2 T3
    ## * : (해당점수 + 바로 전 얻은 점수)*2 , 중첩 가능 -> 4,8배
    ## # : 해당 점수 마이너스, 중첩 가능 -> 2배
    ## 스코어가 여러자리인 경우에 대비
    score = ''
    Area = {'S' : 1, 'D': 2, 'T': 3}
    for i in dartResult:
        if i.isdigit():
            score += i
        elif i in Area:
            answer.append(int(score) ** Area[i])
            score=''
        elif i == '*':
            answer[-1] *=2
            if len(answer)>1:
                answer[-2] *=2
        elif i == '#':
            answer[-1] *=-1
    print(answer)
    return sum(answer)