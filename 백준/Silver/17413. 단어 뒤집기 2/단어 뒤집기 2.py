import sys
word = list(sys.stdin.readline().rstrip())
i=0
while i < len(word):
    if word[i] == '<':
        i+=1
        while word[i]!='>':
            i+=1
        i+=1 # >
    elif word[i].isalnum():
        start = i
        while i<len(word) and word[i].isalnum():
            i+=1
        temp = word[start:i]
        temp.reverse()
        word[start:i] = temp
    else: # 공백처리
        i+=1
print(''.join(word))