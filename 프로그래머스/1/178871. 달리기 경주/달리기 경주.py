def solution(players, callings):
    dict = {players[i] : i for i in range(len(players))}
    for called in callings:
        ## 호명된 선수의 위치
        cur_pos = dict[called]
        ## 앞으로 옮김
        dict[called] -=1
        ## 앞 선수 뒤로
        dict[players[cur_pos-1]] +=1
        ## 실제 선수위치 바꿈
        players[cur_pos -1],players[cur_pos] = players[cur_pos] ,players[cur_pos-1]
    return players