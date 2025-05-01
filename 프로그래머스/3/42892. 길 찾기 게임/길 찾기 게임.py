import sys
sys.setrecursionlimit(100000)
class Node:
    
    def __init__(self,index,x,y):
        self.index = index
        self.x = x
        self.y = y
        self.left = None
        self.right = None
    
    def insert(self,node):
        if node.x < self.x:
            if self.left is None:
                self.left = node
            else:
                self.left.insert(node)
        else:
            if self.right is None:
                self.right = node
            else:
                self.right.insert(node)
        
    def preOrder(self):
        traversal = []

        traversal.append(self.index)
        if self.left:
            traversal += self.left.preOrder()
        if self.right:
            traversal += self.right.preOrder()
        return traversal

    def postOrder(self):
        traversal = []
        if self.left:
            traversal += self.left.postOrder()
        if self.right:
            traversal += self.right.postOrder()
        traversal.append(self.index)
        return traversal
            
    
def solution(nodeinfo):
    nodeinfo = [(i, x, y) for i, (x, y) in enumerate(nodeinfo,start=1)]
    nodeinfo.sort(key=lambda x: (-x[2], x[1]))  # y 내림차순, x 오름차순
    
    root = Node(*nodeinfo[0])
    if len(nodeinfo)>1:
        for data in nodeinfo[1:]:
            node = Node(*data)
            root.insert(node)
    return [root.preOrder(),root.postOrder()]