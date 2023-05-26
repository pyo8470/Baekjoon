formula=str(input())
temp = formula.split('-')
# -를 기준 -> 파씽
result = 0
# -로 시작하는 경우

if formula[0] == '-':
    temp.pop(0)
    k=sum(map(int,temp[0].split('+')))
    result -= k
else:
    k=sum(map(int,temp[0].split('+')))
    result += k

for i in temp[1:]:
    k=sum(map(int,i.split('+')))
    result-=k
print(result)