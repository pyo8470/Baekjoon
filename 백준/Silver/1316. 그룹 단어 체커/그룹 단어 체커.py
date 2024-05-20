a=int(input())
string=[]
count =0
for i in range(a):
  s= input()
  string.append(s)
for a in string:
  last=a[0]  #마지막으로 나온 글자
  dic={} #이미 나온 글자들
  isbreak=False # 멈출지 말지
  for c in a:
    if(last!= c and dic.get(c,-1)!=-1): #딕셔너리 자료형(key value)
      isbreak=True
      break
    dic[c]=dic.get(c,0)+1 # c=key 
    last =c
  if not isbreak:
    count+=1
print(count)
# get함수 (a,b) a= 찾고싶은 딕셔너리 key 값
# b=인자가 없을 경우 출력하고 싶은 값
