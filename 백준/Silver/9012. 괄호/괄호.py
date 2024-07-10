import sys
input = sys.stdin.readline

def is_valid_parentheses(text):
    stack = []
    for c in text:
        if c == '(':
            stack.append(c)
        else :
            if not stack:
                return False
            stack.pop()
    return len(stack) == 0

for _ in range(int(input())):
    text = input().strip()
    if is_valid_parentheses(text):
        print("YES")
    else:
        print("NO")
