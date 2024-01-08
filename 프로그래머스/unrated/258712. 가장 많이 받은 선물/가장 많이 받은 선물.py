def solution(friends, gifts):
    answer = 0
    length = len(friends)
    d = {friends[i] : i for i in range(length)}
    get = [0 for i in range(length)]
    table = [[0]*length for i in range(length)]
    giftIndex = [0 for i in range(length)]
    for st in gifts:
        giver,receiver = st.split()
        table[d[giver]][d[receiver]] +=1
    for i in range(length):
        give = sum(table[i])
        receive = 0
        for j in range(length):
            receive+=table[j][i]
        giftIndex[i] = give -receive 

    for a in range(length):
        for b in range(length):
            if a == b :
                continue
            give = table[a][b]
            
            receive = table[b][a]
            if give> receive:
                get[a] += 1
                continue
            if give == receive:
                if giftIndex[a] > giftIndex[b]:
                    get[a] +=1
            
    answer = max(get)
    return answer