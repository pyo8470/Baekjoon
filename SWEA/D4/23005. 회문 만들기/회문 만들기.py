
for t in range(int(input())):
    S = input().strip()
    answer = 0
    l, r = 0, len(S) - 1
    while l < r:
        if S[l] == S[r]:
            l += 1;
            r -= 1
        elif S[l] == 'x':
            l += 1;
            answer += 1
        elif S[r] == 'x':
            r -= 1
            answer+=1
        else:
            answer = -1
            break

    print(answer)
