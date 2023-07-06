import sys

N = int(sys.stdin.readline().rstrip())
dance = {'ChongChong'}
for i in range(N):
    A, B = sys.stdin.readline().rstrip().split()
    if A in dance:
        dance.add(B)
    if B in dance:
        dance.add(A)
    
print(len(dance))