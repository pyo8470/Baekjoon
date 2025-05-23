
for t in range(int(input())):
    henchman = list(map(int,input().split()))
    height_sum = sum(henchman)
    result = max(henchman) + 1
    while (height_sum + result)%(len(henchman)+1) !=0:
        result+=1
    print(result)
    
