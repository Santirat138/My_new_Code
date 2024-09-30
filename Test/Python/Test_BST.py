class node:
    def __init__(self, numIn):
        self.num=numIn
        self.left=None
        self.right=None

class BST:
    def __init__(self):
        self.root=None

    def insertNum(self, currNode, newNum):
        if currNode is None:
            return node(newNum)
        if currNode.num>newNum:
            currNode.left=self.insertNum(currNode.left, newNum)
        elif currNode.num<newNum:
            currNode.right=self.insertNum(currNode.right, newNum)
        return currNode
    
    def showPostorder(self, currNode):
        if currNode is not None:
            self.showPostorder(currNode.left)
            self.showPostorder(currNode.right)
            print(currNode.num, end=" ")
        else:
            print("")

    def countHeight(self, currNode):
        if currNode is None:
            return 0
        lHeight=self.countHeight(currNode.left)
        rHeight=self.countHeight(currNode.right)
        if lHeight>rHeight:
            return lHeight+1
        else:
            return rHeight+1
        
    def showCurrLevel(self, currNode, levelIn):
        if currNode is None:
            return
        if(levelIn==0):
            print(currNode.num, end=" ")
        else:
            self.showCurrLevel(currNode.left, levelIn-1)
            self.showCurrLevel(currNode.right, levelIn-1)

    def showLevelorder(self):
        treeHeight=self.countHeight(self.root)
        for i in range(0, treeHeight, 1):
            print(self.showCurrLevel(self.root, i))

    def findMaxLeftNum(self, currNode):
        if(currNode.left is not None):
            currNode=currNode.left
            while currNode.right is not None:
                currNode=currNode.right
            return currNode
        return None
    
    def deleteNum(self, targetNum):
        
#----------------- main
bst=BST()
bst.root=bst.insertNum(bst.root, 50)
bst.root=bst.insertNum(bst.root, 25)
bst.root=bst.insertNum(bst.root, 75)
bst.root=bst.insertNum(bst.root, 60)
bst.root=bst.insertNum(bst.root, 80)
bst.root=bst.insertNum(bst.root, 65)
print("")
bst.showLevelorder()