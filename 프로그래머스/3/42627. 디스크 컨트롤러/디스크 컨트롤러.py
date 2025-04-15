import heapq

def solution(jobs):
    jobs.sort(key=lambda x: x[0])  # 필요는 없지만 무방함

    q = []

    cur_time = 0
    job_index = 0
    total_wait = 0

    n = len(jobs)
    while job_index < n or q:
        # 현재 시간보다 요청 시간이 작거나 같은 job을 큐에 넣는다
        while job_index < n and jobs[job_index][0] <= cur_time:
            heapq.heappush(q, (jobs[job_index][1], jobs[job_index][0],job_index))
            job_index += 1

        if q:
            duration, request, number = heapq.heappop(q)
            cur_time += duration
            wait = cur_time - request
            total_wait += wait  # ✅ 변수명 수정
        else:
            # 작업이 없으면 현재 시간을 다음 작업의 요청 시각으로
            cur_time = jobs[job_index][0]

    return total_wait // n
