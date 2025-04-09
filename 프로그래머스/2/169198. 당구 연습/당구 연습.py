def solution(m, n, startX, startY, balls):
    
    # 경로상에 공이 존재해선 안된다.
    ## 쿠션 계산 -> 가까운 벽
    answer = []
    for ballX,ballY in balls:
        min_dist_sq = float('inf')
        ## 공과의 거리 계산
        ## 원쿠션(=벽을 한 번 맞고 공을 맞히는 것)은 
        ## 실제로는 직선 경로로 맞출 수 있는 대칭 좌표를 향해 쏘는 것과 같다. (중등인가 고등수학때, 최단거리 구하는 문제에서 좌표 확장시킨것과 비슷?)
        candidates = [
            # 왼쪽
            (-ballX, ballY),
            # 오른쪽
            (2 * m - ballX, ballY),
            # 아래
            (ballX, -ballY),
            # 위
            (ballX, 2 * n - ballY)
        ]

        for x,y in candidates:
            dx = startX-x
            dy = startY-y
            
            
            ## 세로로 겹치는 경우
            ## + 1-1. ballY < startY -> 내 공이 목표보다 오른쪽에 있음
            ## + 1-2. y < ballY -> 후보군(y) 가 ball보다 왼쪽 : 왼쪽벽에 부딪힌다는 뜻 반대는 반대
            if x == startX and ((ballY < startY and y < ballY) or (ballY > startY and y > ballY)):
                continue
            ## 가로로 겹치는 경우
            if y == startY and ((ballX < startX and x < ballX) or (ballX > startX and x > ballX)):
                print(y,startY, ballX,startX,x)
                continue   
            
            dist_sq = dx**2 + dy**2
            min_dist_sq = min(min_dist_sq, dist_sq)
        answer.append(min_dist_sq)
    
    return answer

    