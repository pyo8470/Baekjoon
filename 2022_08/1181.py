N = int(input())
x=[]
for i in range(N):
    x.append(input())
    
set_word=list(set(x)) ## 중복 제거
set_word.sort()
set_word.sort(key=len)
for i in set_word:
    print(i)