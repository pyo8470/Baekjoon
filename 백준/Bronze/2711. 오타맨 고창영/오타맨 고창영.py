import sys
input = sys.stdin.readline

T = int(input())
employee = {}
for i in range(T):
    index, word = map(str,input().split())
    index = int(index) -1
    print(word[:index]+word[index+1:])