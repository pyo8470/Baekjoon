def solution(rows, columns, queries):
    answer = []
    matrix = []
    for r in range(rows):
	    matrix.append([a for a in range(r*columns+1, (r+1)*columns+1)])


    for y1, x1, y2, x2 in queries:
        y1 -= 1
        y2 -= 1
        x1 -= 1
        x2 -= 1
        tmp = matrix[y1][x1]
        smallest = tmp

        # 위로 이동
        for y in range(y1 + 1, y2 + 1):
            matrix[y - 1][x1] = matrix[y][x1]
            smallest = min(matrix[y][x1], smallest)

        # 왼쪽으로 이동
        for x in range(x1 + 1, x2 + 1):
            matrix[y2][x - 1] = matrix[y2][x]
            smallest = min(matrix[y2][x - 1], smallest)

        # 아래로 이동
        for y in range(y2, y1, -1):
            matrix[y][x2] = matrix[y - 1][x2]
            smallest = min(matrix[y][x2], smallest)

        # 오른쪽으로 이동
        for x in range(x2, x1, -1):
            matrix[y1][x] = matrix[y1][x - 1]
            smallest = min(matrix[y1][x], smallest)

        matrix[y1][x1 + 1] = tmp
        answer.append(smallest)

    return answer