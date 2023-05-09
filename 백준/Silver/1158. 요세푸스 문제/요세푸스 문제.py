
N,K = map(int,input().split())
queue = [i for i in range(1,N+1)]
Result=[]
## K칸씩 뛰어 보내기
index = K-1 
for i in range(N):
    if index>=len(queue):
        index=index%len(queue)
    Result.append(str(queue.pop(index)))
    # K번째 사람이 사라짐 -> +K 하게 될 시, 하나 더 넘어가 버림 
    index+=K-1
print('<',', '.join(Result),">",sep='')