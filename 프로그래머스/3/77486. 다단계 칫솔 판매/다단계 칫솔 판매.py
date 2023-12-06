def solution(enroll, referral, seller, amount):
    length = len(enroll)
    answer = [0 for i in range(length+1)]
    d = {}
    parents = [i for i in range(length+1)]  # 각자 자신을 부모로 초기화
    # 이름-번호로 딕셔너리에 저장
    for i in range(length):
        d[enroll[i]] = i + 1
    # 추천인 입력
    for i in range(length):
        if referral[i] == "-":  # 민호가 추천인
            parents[i + 1] = 0
        else:
            parents[i + 1] = d[referral[i]]
    #계산
    def calculate(money,number):
        ## number == 현재 판매원
        ## 민호 or 줄돈 x
        if parents[number] == number or money // 10 == 0:
            answer[number] += money
            return
        ## 위로 보낼 돈
        upMoney = money //10
        ## 가질 돈
        haveMoney = money-upMoney
        answer[number] += haveMoney
        ## 부모로 턴 드로우
        calculate(upMoney,parents[number])
    for i in range(len(seller)):
        calculate(amount[i]*100,d[seller[i]])
    return answer[1:]