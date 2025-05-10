def solution(book_time):
    answer = 0
    def time_to_minute(time):
        h,m = time.split(":")
        return int(h)*60 + int(m)
    
    times = []
    time_table = [0]*1440
    for time in book_time:
        s = time_to_minute(time[0])
        e = time_to_minute(time[1])+10 # 청소시간 포함
        times.append((s,e))
    
    times.sort()
    for start,end in times:
        if end >= 1440:
            end = 1440-1
        for i in range(start,end):
            time_table[i] +=1
        # print(time_table[start])
    return max(time_table)
    ## 누적합 풀이
    
#     print(times)
    
#     ## 로직 생각
#     ## 시작시간 기준으로 정렬을 했다.
#     ## 현재 손님의 입실 시간(start)이 
#     ## 이미 방에 들어가있는 손님들의 퇴실시간의 최솟값(heap[0])보다 작거나 같다면
#     ## 새로운 방을 구해야한다.
#     heap = []
#     import heapq
    
#     for start,end in times:
#         ## 방 재활용 
#         if heap and heap[0] <= start:
#             heapq.heappop(heap)
#         heapq.heappush(heap,end)
#         # print(heap)
    # return len(heap)