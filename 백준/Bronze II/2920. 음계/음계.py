a = [1,2,3,4,5,6,7,8]
r = [8,7,6,5,4,3,2,1]
k = list(map(int,input().split()))
print('ascending' if a == k else('descending' if r == k else 'mixed'))