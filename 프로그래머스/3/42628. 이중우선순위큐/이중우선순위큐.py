import heapq

def solution(operations):
    minHeap = []
    maxHeap = []
    dic = {}

    for op in operations:
        command, num = op.split()
        num = int(num)

        if command == 'I':
            heapq.heappush(minHeap, num)
            heapq.heappush(maxHeap, -num)
            dic[num] = dic.get(num, 0) + 1

        elif command == 'D':
            if not dic:
                continue

            if num == 1:
                while maxHeap and (-maxHeap[0] not in dic or dic[-maxHeap[0]] < 1):
                    heapq.heappop(maxHeap)
                if maxHeap:
                    val = -heapq.heappop(maxHeap)
                    dic[val] -= 1
                    if dic[val] == 0:
                        del dic[val]

            else:
                while minHeap and (minHeap[0] not in dic or dic[minHeap[0]] < 1):
                    heapq.heappop(minHeap)
                if minHeap:
                    val = heapq.heappop(minHeap)
                    dic[val] -= 1
                    if dic[val] == 0:
                        del dic[val]

    if dic:
        keys = dic.keys()
        return [max(keys), min(keys)]
    else:
        return [0, 0]
