import sys
N=int(input())
Deque = []
for i in range(N):
    command=sys.stdin.readline().split()
    if len(command) == 2:
        if command[0] == 'push_back' :
            Deque.append(int(command[1]))
        if command[0] == 'push_front':
            Deque.insert(0,int(command[1]))  
    else:
        if command[0] == 'pop_front':
            if len(Deque) != 0:
                print(Deque.pop(0))
            else:
                print(-1)
        if command[0] == 'pop_back':
            if len(Deque) != 0:
                print(Deque.pop(-1))
            else:
                print(-1)
        if command[0] == 'size':
            print(len(Deque))
        if command[0] == 'empty':
            if len(Deque) != 0:
                print(0)
            else:
                print(1)
        if command[0] == 'front':
            if len(Deque) != 0:
                print(Deque[0])
            else:
                print(-1)
        if command[0] == 'back':
            if len(Deque) != 0:
                print(Deque[-1])
            else:
                print(-1)