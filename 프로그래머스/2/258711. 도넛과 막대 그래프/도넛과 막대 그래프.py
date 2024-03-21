
def solution(edges):
    answer = [0,0,0,0]
#     각 노드별,

    vertex = {}
    for e in edges:
        ## out in
        start, end = e[0],e[1]
        if start not in vertex.keys():
            vertex[start] = [0,0] ## in, out
        if end not in vertex.keys():
            vertex[end] = [0,0] ## in, out
        if start == end:
            vertex[end][0] += 2
        else:
            vertex[end][0] += 1
        vertex[start][1] += 1
    for key in vertex.keys():
        # print(key,vertex[key])
        edge_in,edge_out= vertex[key][0],vertex[key][1]
        #경우 1) out>2: ---> 이 노드가 시작 정점
        if edge_out > 2:
            answer[0] = key
            
        #경우 2) out==2:
        #       if in>0: ---> 8자 그래프 갯수 +=1
        #       else: ---> 이 노드가 시작 정점
        elif edge_out == 2:
            if edge_in > 0 :
                answer[3] += 1
            else :
                answer[0] = key
                
        #경우 3) out==1: 흔한 노드.. 무시
        elif edge_out == 1:
            continue
                
        #경우 4) out==0: ---> 직선 그래프 갯수 +=1
        elif edge_out == 0:
            answer[2]+=1
        ## 도넛의 경우
        start = answer[0]
    answer[1] = vertex[start][1] - sum(answer[2:])
        
    return answer