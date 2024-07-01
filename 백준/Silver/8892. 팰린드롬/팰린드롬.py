import sys
from itertools import combinations

def is_palindrome(word1, word2):
    combined1 = word1 + word2
    combined2 = word2 + word1
    
    if combined1 == combined1[::-1]:
        return combined1, True
    if combined2 == combined2[::-1]:
        return combined2, True
    return "", False

input = sys.stdin.readline

for _ in range(int(input())):
    k = int(input())
    words = [input().strip() for _ in range(k)]
    found = False
    
    for word1, word2 in combinations(words, 2):
        answer, is_pal = is_palindrome(word1, word2)
        if is_pal:
            print(answer)
            found = True
            break
    
    if not found:
        print(0)
