def solution(board):
    answer = 0
    
    """
    "O"를 표시할 차례인데 "X"를 표시하거나 반대로 "X"를 표시할 차례인데 "O"를 표시한다.
    -> 서로 숫자 밸런스가 안 맞음
    선공이나 후공이 승리해서 게임이 종료되었음에도 그 게임을 진행한다.
    -> 승리 요건 검사
    """    
    board_state = [i for li in board for i in li]
    
    ## 게임 종료 여부
    def isBingo(c):
        ## 가로 상황
        for i in range(3):
            state = set(board[i])
            if state == {c}: return True
        ## 세로 상황
        for col in range(3):
            state = set()
            for row in range(3):
                state.add(board[row][col])
            if state == {c}: return True
        ## 대각선 상황
        stateRightDown = set()
        stateLeftDown = set()
        for i in range(3):    
            stateRightDown.add(board[i][i])
            stateLeftDown.add(board[i][2-i])
        if stateRightDown == {c}:return True
        if stateLeftDown == {c}: return True
        return False
    
    ## x의 개수와 o의 개수
    xCount = board_state.count('X')
    oCount = board_state.count('O')
    
    # if(cntO==cntX) return !isBingo('O')?1:0;
    #     else if(cntO==cntX+1) return !isBingo('X')?1:0;
    #     else return 0;
    if xCount == oCount:
        return 1 if not isBingo('O') else 0
    if xCount + 1 == oCount:
        return 1 if not isBingo('X') else 0
    return answer