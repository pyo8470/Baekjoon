

for _ in range(1, int(input()) + 1):
    sudoku = [list(map(int, input().split())) for i in range(9)]
    is_correct = True
    
    # 가로 검사
    for y in range(9):
        if len(set(sudoku[y])) != 9:
            is_correct = False
            break
    
    # 세로 검사
    if is_correct:
        sudoku2 = list(zip(*sudoku))
        for y in range(9):
            if len(set(sudoku2[y])) != 9:
                is_correct = False
                break
    
    # 3x3 서브 그리드 검사
    if is_correct:
        for y in range(0, 9, 3):
            for x in range(0, 9, 3):
                check = set()
                for i in range(3):
                    for j in range(3):
                        check.add(sudoku[y+i][x+j])
                if len(check) != 9:
                    is_correct = False
                    break
            if not is_correct:
                break
    
    print(f'#{_} 1') if is_correct else print(f'#{_} 0')
