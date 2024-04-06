A = input()
B = input()
length_A = len(A)+1
length_B = len(B) +1
LCS = [[0 for i in range(length_B)] for j in range(length_A)]
for i in range(1,length_A) :
    for j in range(1,length_B):
        if A[i-1] == B[j-1]:
            LCS[i][j] = LCS[i-1][j-1] + 1
        else:
            LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1])
print(max(LCS[-1]))