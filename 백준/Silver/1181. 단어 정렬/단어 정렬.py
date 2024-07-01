import sys
input = sys.stdin.readline

N = int(input())
words = set()
for i in range(N):
    word = input().strip()
    words.add(word)
words = sorted(words,key= lambda x : (len(x),x) )
for i in range(len(words)):
    print(words[i])