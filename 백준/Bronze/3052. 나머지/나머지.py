import sys
input = sys.stdin.readline

mod = set()
for _ in range(10):
    mod.add(int(input())%42)
print(len(mod))