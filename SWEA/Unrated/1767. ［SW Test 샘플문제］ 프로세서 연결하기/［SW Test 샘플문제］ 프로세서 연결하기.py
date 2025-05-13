directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
for t in range(int(input())):
    N = int(input())
    board = [list(map(int, input().split())) for i in range(N)]
    locations = []
    visited = [[False] * N for i in range(N)]
    for y in range(N):
        for x in range(N):
            if board[y][x] == 1:
                locations.append((x, y))
    answer = float('inf')
    connected_max = 0


    def is_side(x, y):
        return x == 0 or x == N - 1 or y == 0 or y == N - 1


    ##
    def dfs(length, connected_count, index):
        global answer, connected_max
        if index == len(locations):
            # print(connected_count)
            check(connected_count, length)
            return

        x, y = locations[index]

        if is_side(x, y):
            # check(connected_count, length)
            dfs(length, connected_count + 1, index + 1)

        for dx, dy in directions:
            nx, ny = x, y
            cur_length = 0

            ## 전선 연결
            while True:
                nx += dx
                ny += dy
                if nx < 0 or nx >= N or ny < 0 or ny >= N:
                    break
                if board[ny][nx] == 1 or board[ny][nx] == 2:
                    cur_length = 0
                    break
                cur_length += 1

            ## 가능한 경우
            if cur_length > 0:
                for i in range(1, cur_length + 1):
                    board[y + i * dy][x + i * dx] = 2
                dfs(length+cur_length,connected_count+1,index+1)
                for i in range(1, cur_length + 1):
                    board[y + i * dy][x + i * dx] = 0

        """
        연결하지않고 그냥 넘어감
        """
        dfs(length,connected_count,index+1)
    def check(connected_count, length):
        global connected_max, answer
        if connected_count > connected_max:
            connected_max = connected_count
            answer = length
        elif connected_count == connected_max:
            answer = min(answer, length)


    dfs(0, 0, 0)
    print(f"#{t+1} {answer}")