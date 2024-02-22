T = int(input())
## 2 1 -> 5 = 3*2 -1 , 3 -> 3 = 4 - 1
## 
for i in range(T):
    n = int(input())
    kinds = {}
    for i in range(n):
        cloth,kind = map(str,input().split())
        if kind in kinds:
            kinds[kind].append(cloth)
        else:
            kinds[kind] = [cloth]
    cnt = 1
    for k,c in kinds.items():
        cnt *= len(c)+1
    print(cnt-1)