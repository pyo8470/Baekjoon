import sys
input = sys.stdin.readline

N, M = map(int,input().split())
card = list(map(int,input().split()))
answer = 0
from itertools import combinations
comb = combinations(card,3)
for cards in comb:
    S = sum(cards)
    if M-S >= 0:
        answer = max(answer,S)

print(answer)