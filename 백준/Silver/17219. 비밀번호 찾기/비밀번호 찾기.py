N,M = map(int,input().split())
import sys
dic = {}
for i in range(N):
    사이트, 비번 = map(str,sys.stdin.readline().split())
    dic[사이트] = 비번
for i in range(M):
    print(dic[sys.stdin.readline().strip()])