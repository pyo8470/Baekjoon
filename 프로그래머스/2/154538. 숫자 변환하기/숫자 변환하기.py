def solution(x, y, n):
    answer = -1
    
    def bfs():
        from collections import deque
        q=deque([(x,0)])
        visited = set()
        visited.add(x)
        while q:
            cur, count = q.popleft()
            if cur == y:
                return count
            for next_ in [cur+n, cur*2, cur*3]:
                if next_<=y and next_ not in visited:
                    visited.add(next_)
                    q.append((next_,count+1))
    count = bfs()
    return -1 if count == None else count