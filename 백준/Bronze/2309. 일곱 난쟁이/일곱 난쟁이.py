import sys
from itertools import combinations
input = sys.stdin.readline

Dwarf = []
for i in range(9):
    Dwarf.append(int(input()))

for dwarf_comb in combinations(Dwarf,7):
    if sum(dwarf_comb) == 100:
        for height in sorted(dwarf_comb):
            print(height)
        break
