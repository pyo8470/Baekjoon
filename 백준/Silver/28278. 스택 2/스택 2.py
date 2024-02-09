N = int(input())
import sys
stack = []
for i in range(N):
    command = list(sys.stdin.readline().split())
    if len(command) == 2 :
        command, X =command[0], command[1]
        stack.append(X)
        continue
    elif len(command) == 1:
        command = int(command[0])
        if command == 2:
            if stack : 
                print(stack.pop())
            else : print(-1)
            
        elif command == 3:
            print(len(stack))
            
        elif command == 4:
            if len(stack) == 0:
                print(1)
            else:
                print(0)
        elif command == 5:
            if stack : 
                print(stack[-1])
            else : print(-1)