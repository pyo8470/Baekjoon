import sys
input = sys.stdin.readline

N = int(input())
coord = []
for i in range(N):
    x,y = map(int,input().split())
    coord.append([x,y])

coord.sort(key=lambda x : (x[0],x[1]))
for i in range(N):
    print(coord[i][0],coord[i][1])