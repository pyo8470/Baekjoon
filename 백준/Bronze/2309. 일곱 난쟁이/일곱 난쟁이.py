import sys
from itertools import combinations
input = sys.stdin.readline

Dwarf = []
for i in range(9):
    Dwarf.append(int(input()))

comb = combinations(Dwarf,7)
for dwarf_comb in comb:
    if sum(dwarf_comb) == 100:
        for height in sorted(dwarf_comb):
            print(height)
        break
