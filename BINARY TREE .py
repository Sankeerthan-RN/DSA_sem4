import math
from collections import deque


class BinaryTree:
    # @start-editable@

    class node:
        def __init__(self):
            self.element = 0
            self.parent = None
            self.lefchild = None
            self.rightchild = None

    def __init__(self):
        self.root = self.node()
        self.sz = 0

    def buildTree(self, eltlist):
        nodelist = []
        nodelist.append(None)
        for i in range(len(eltlist)):
            if (i != 0):
                if (eltlist[i] != -1):
                    tempnode = self.node()
                    tempnode.element = eltlist[i]
                    if (i != 1):
                        tempnode.parent = nodelist[i // 2]
                        if (i % 2 == 0):
                            nodelist[i // 2].lefchild = tempnode
                        else:
                            nodelist[i // 2].rightchild = tempnode
                    nodelist.append(tempnode)
                else:
                    nodelist.append(None)
        self.root = nodelist[1]
        self.sz = len(nodelist)
        return nodelist

    def inorderTraverse(self, root):
        if root:

            self.inorderTraverse(root.lefchild)

            print(root.element, end=" ")

            self.inorderTraverse(root.rightchild)

        return

    def print(self):
        pass

    def preorderTraverse(self, root):
        if root:
            print(root.element, end=" ")

            self.preorderTraverse(root.lefchild)

            self.preorderTraverse(root.rightchild)

    def postorderTraverse(self, root):
        if root:
            self.postorderTraverse(root.lefchild)

            self.postorderTraverse(root.rightchild)

            print(root.element, end=" ")

    def levelorderTraverse(self, root):



        nodeDeque = deque([root])

        while nodeDeque:
            levelLen = len(nodeDeque)
            print(levelLen)

            levelNodes = []
            for i in range(levelLen):
                curNode = nodeDeque.popleft()
                levelNodes.append(curNode.element)
                if curNode.lefchild:
                    nodeDeque.append(curNode.lefchild)
                if curNode.rightchild:
                    nodeDeque.append(curNode.rightchild)

            #print(*levelNodes, end=" ")

        return 0

    def findDepth(self, s):
        if s:
            return 1 + self.findDepth(s.parent)
        else:
            return -1

    def findHeight(self, s):
        if s:
            return 1 + max(self.findHeight(s.lefchild), self.findHeight(s.rightchild))
        else:
            return -1

    # @end-editable@


def main():
    tree = BinaryTree()
    arraySize = int(input())
    arr = list(map(int, input().split()))
    nlist = tree.buildTree(arr)
    inputs = int(input())
    while inputs > 0:
        command = input()
        operation = command.split()
        if (operation[0] == "IN"):
            tree.inorderTraverse(tree.root)
            print()
        elif (operation[0] == "PR"):
            tree.preorderTraverse(tree.root)
            print()
        elif (operation[0] == "PO"):
            tree.postorderTraverse(tree.root)
            print()
        elif (operation[0] == "L"):
            tree.levelorderTraverse(tree.root)
            print()
        elif (operation[0] == "D"):
            pos = int(operation[1])
            print(tree.findDepth(nlist[pos]))
        elif (operation[0] == "H"):
            pos = int(operation[1])
            print(tree.findHeight(nlist[pos]))
        inputs -= 1


if __name__ == '__main__':
    main()