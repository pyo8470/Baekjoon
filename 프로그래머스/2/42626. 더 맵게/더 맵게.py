import heapq

def solution(scoville, K):
    ## a +   b*2
    q = scoville[:]
    heapq.heapify(q)
    answer = 0
    
    while not all(x >= K for x in q) and len(q) >= 2:
        a = heapq.heappop(q)
        b = heapq.heappop(q)
        heapq.heappush(q,a+b*2)
        answer+=1
    if not all(x >= K for x in q):
        return -1
    return answer