def solution(name, yearning, photo):
    answer = []
    points = { name[i] : yearning[i] for i in range(len(name))}
    for p in photo:
        c = 0
        for na in p:
            if na in points:
                c+=points[na]
        answer.append(c)
    return answer