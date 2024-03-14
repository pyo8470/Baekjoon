import sys
input = sys.stdin.readline
N = int(input())

tree = {}
for i in range(N):
    root ,left,right = map(str,input().split())
    tree[root] = [left,right]


## 전위
def pre_order(root):
    if root != '.':

        print(root,end='')
        ## 왼쪽
        pre_order(tree[root][0])
        ## 오른쪽
        pre_order(tree[root][1])
    else:
        return
## 중위
def in_order (root):
        
    if root != '.':
        ## 왼쪽
        in_order(tree[root][0])
        ##루트
        print(root,end='')
        ## 오른쪽
        in_order(tree[root][1])
    else:
        return
## 후위
def post_order(root):
    
    if root != '.':
        ## 왼쪽
        post_order(tree[root][0])
        ## 오른쪽
        post_order(tree[root][1])
        ##루트
        print(root,end='')
pre_order('A');print()
in_order('A');print()
post_order('A')