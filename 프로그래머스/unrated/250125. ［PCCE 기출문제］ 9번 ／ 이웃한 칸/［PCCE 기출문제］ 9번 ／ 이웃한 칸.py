def solution(board, h, w):
    answer = 0
    # 위 아래 왼쪽 오른쪽
    x = [0,0,-1,1]
    y = [-1,1,0,0]
    length =len(board)
    color = board[h][w]
    for i in range(4):
        dx, dy = w+x[i],h+y[i]
        if 0<=dx <length and 0<=dy<length:
            if color == board[dy][dx]:
                answer+=1
    return answer