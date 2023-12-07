import math 
def calculate(fees,time):
    ## 공식: 기본 요금 + ((이용시간 - 기본 시간)//단위시간+1) x 요금
    t = time-fees[0]
    if t <0 : t = 0
    return fees[1] + math.ceil((t/fees[2]))*fees[3]
def solution(fees, records):
    answer = []
    cars = set()
    for query in records:
        time, number, status = query.split()
        cars.add(number)
    dict = {key : 0 for key in cars}
    for query in records:
        time, number, status = query.split()
        hours,minutes = int(time[0:2]),int(time[3:])
        h1,m1 = 23-hours, 59-minutes
        ## IN만 하는 경우가 있다
        ## 따라서 23:59에서 IN한 시간을 뺀다(나중에 OUT하더라도 OUT보다 IN의 크기가 큼)
        if status == 'IN':
            ## 요금 정산
            dict[number] += h1*60+m1
        else :
            ## IN한 시간(23 59 - IN) -(23 59 + OUT)
            ## == OUT-IN
            dict[number] -= h1*60+m1
    dict = list(dict.items())
    ##정렬
    dict.sort()
    for number,time in dict:
        answer.append(calculate(fees,time))
    return answer