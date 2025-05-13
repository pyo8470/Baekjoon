for t in range(int(input())):
    answer = 0
    N = int(input())
    prices = list(map(int,input().split()))
    maxPrice = prices[-1]
    for i in range(N-2,-1,-1):
        prev_price = prices[i]
        if prev_price >= maxPrice:
            maxPrice = prev_price
        else:
            answer+=(maxPrice-prev_price)
    print(f"#{t+1} {answer}")