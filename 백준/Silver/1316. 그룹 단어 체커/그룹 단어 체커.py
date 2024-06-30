import sys
input = sys.stdin.readline
answer = 0
for i in range(int(input())):
    word = input().strip()
    checker = set()
    is_group_word = True
    last = word[0]; checker.add(last)
    for i in range(1,len(word)):
        current = word[i]
        if last != current and current in checker:
            is_group_word = False
            break
        checker.add(current)
        last = current
    if is_group_word :
        answer+=1
print(answer)