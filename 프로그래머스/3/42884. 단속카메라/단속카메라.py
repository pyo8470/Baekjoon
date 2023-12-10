def solution(routes):
    answer = 0
    ## 진입지점 기준 정렬
    routes.sort(key = lambda x : x[1])
    print(routes)
    camera = routes[0][0]-1
    for route in routes:
        if camera < route[0]:
            answer += 1
            camera = route[1]
            
    return answer