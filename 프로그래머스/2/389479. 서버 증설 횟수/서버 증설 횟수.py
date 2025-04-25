

def solution(players, m, k):
    answer = 0
    server = [0]*24
    for t, num in enumerate(players):
        ## k시간 전에 켜져있었다면 제거
        server_req = num//m
        if t-k >= 0 and server[t-k] >= 1:
            server[t-k] = 0
        total_server = sum(server)
        if server_req and total_server < server_req:
            server[t] = (server_req-total_server)
            answer += server[t]
        # print(server)
    return answer