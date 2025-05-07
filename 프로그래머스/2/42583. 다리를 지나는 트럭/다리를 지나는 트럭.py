from collections import deque
def solution(bridge_length, weight, truck_weights):
    bridge = deque([0] * bridge_length)
    time = 0
    total_weight = 0  
    # 현재 다리 위의 트럭 총 무게
    truck_queue = deque(truck_weights)
    
    while bridge:
        time+=1
        
        out = bridge.popleft()
        total_weight -= out
        
        if truck_queue:
            if total_weight + truck_queue[0] <= weight:
                truck = truck_queue.popleft()
                bridge.append(truck)
                total_weight += truck
            else:
                bridge.append(0)
        
    return time