n = int(input())

if n == 0:
    print(0)
else:
    import sys
    opinion = [int(sys.stdin.readline()) for i in range(n)]
    opinion.sort()
    cut = round(n*(0.15)+0.0000000001)
    answer = round(sum(opinion[cut:n-cut])/(n-2*cut)+0.0000000001)
    print(answer)
