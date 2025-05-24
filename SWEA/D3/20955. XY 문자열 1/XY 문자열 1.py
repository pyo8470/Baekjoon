for t in range(int(input())):
    
    S = input().strip()
    from collections import deque
    E = input().strip()
    
    
    def solution(S,E):
        queue = deque([E])
        visited = set()
        while queue:
            current = queue.popleft()
            if current == S:
                return "Yes"
            if len(current) < len(S) :#or current in visited:
                continue
            #visited.add(current)
            if current[-1] == 'X':
                queue.append(current[:-1])
            else:
                queue.append(current[:-1][::-1])
        return "No"
    
    print(f"#{t+1} {solution(S,E)}")