class node:
    def __init__(self, num):
        self.num=num
        self.right=None
nullNode=node(-1)
class linkList:
    def __init__(self):
        self.head=None
        self.tail=None

    def addFirst(self, newNum):
        newNode=node(newNum)
        if(self.head is not None):
            newNode.right=self.head
        else:
            self.tail=newNode
        self.head=newNode

    def addLast(self, newNum):
        newNode=node(newNum)
        if(self.tail is not None):
            self.tail.right=newNode
        else:
            self.head=newNode
        self.tail=newNode
        
    def showLL(self):
        currNode=self.head
        while currNode is not None:
            print(currNode.num)
            currNode=currNode.right

    def findNum(self, targetNum):
        currNode=self.head
        while currNode is not None:
            if currNode.num is targetNum:
                return currNode
            else:
                currNode=currNode.right
        return nullNode
    def deleteNum(self, targetNum):
        currNode=self.head
        while currNode.right is not None:
            if currNode.right.num is targetNum:
                delNode=currNode.right
                currNode.right=delNode.right
                delNode.right=None
                return 
            else:
                currNode=currNode.right
        print("Not found.")
ll=linkList()
for i in range(1, 6, +1):
    ll.addFirst(i)
ll.deleteNum(50)
ll.showLL()