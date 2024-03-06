def calculate(y,m,d,month):
    if d == 1 :
        d = 28
        m -=1
    else:
        d-=1
    y += (m+month)//12
    m = (m+month)%12
    if m == 0 :
        m = 12
        y -= 1
    
    return y,m,d
def solution(today, terms, privacies):
    from datetime import datetime
    dic = {}
    count = 1
    # 모든달은 28일
    answer=[]
    for t in terms:
        code, expire = t.split()
        dic[code] = int(expire)
    t_y,t_m,t_d = today.split('.')
    t_y,t_m,t_d = int(t_y),int(t_m),int(t_d)
    today = datetime(t_y,t_m,t_d)
    for t in privacies:
        date, code = t.split()
        y,m,d = date.split(".")
        y,m,d = calculate(int(y),int(m),int(d),dic[code])
        print(y,m,d)
        date = datetime(y,m,d)
        if date < today:
            answer.append(count)
        count+=1
    return answer