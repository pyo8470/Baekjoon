import sys
input = sys.stdin.readline

N = int(input())
sold_book = {}

for i in range(N):
    title = input().strip()
    if title not in sold_book:
        sold_book[title] = 1
    else:
        sold_book[title] +=1
answer = sorted(sold_book.items(),key=lambda item: (-item[1],item[0]))
print(answer[0][0])