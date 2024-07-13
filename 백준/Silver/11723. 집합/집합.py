import sys
input = sys.stdin.readline
bit = 0
M = int(input())
for _ in range(M):
    command = input().split()
    if command[0] == 'all':
        bit = (1<<20) - 1
    elif command[0] == 'empty':
        bit = 0
    else:
        command,num = command[0], int(command[1]) - 1
        if command == 'add':
            bit |= (1<<num)
        elif command == 'remove':
            bit &= ~(1<<num)
        elif command == 'check':
            if bit & (1<<num) == 0:
                print(0)
            else:
                print(1)
        elif command == 'toggle':
            bit = bit^(1<<num)