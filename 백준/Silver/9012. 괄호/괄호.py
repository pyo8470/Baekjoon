import sys
input = sys.stdin.readline

for i in range(int(input())):
    stack = []
    text = input().strip()
    is_right = True
    for c in text:
        if c == '(':
            stack.append(c)
        else:
            if len(stack) == 0:
                is_right = False
                break
            else:
                stack.pop()
    if len(stack) != 0:
        is_right = False
    print("YES") if is_right else print("NO ")