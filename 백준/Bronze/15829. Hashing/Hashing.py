L = int(input())
import sys
S, sum= sys.stdin.readline().strip(), 0

for i in range(L):
    sum+=(ord(S[i])-96)*(31**i)
print(sum%1234567891)