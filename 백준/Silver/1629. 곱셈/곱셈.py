A,B,C= map(int,input().split())

def pow(a,k):
    if k == 1:
        return a%C
    else:
        n = pow(a,k//2)
        if k % 2 == 0:
            return n*n%C
        else:
            return a*n*n%C
            
print(pow(A,B))