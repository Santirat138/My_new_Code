class node:
    def __init__(self, numIn):
        self.num=numIn
        self.next=None

class linkList:
    def __init__(self):
        self.head=None
    
    def addFirst(self, newNum):
        newNode=node(newNum)
        if self.head is not None:
            newNode.next=self.head
        else:
            self.head=newNode
        self.head=newNode
    
    def showLL(self):
        currNode=self.head
        while currNode is not None:
            print(currNode.num, end=" ")
            currNode=currNode.next
        print("")
        
    def deleteNum(self, targetNum):
        currNode=self.head
        if targetNum is self.head.num:
            self.head=self.head.next
            currNode.next=None
            return 
        while currNode is not None:
            if currNode.next.num is targetNum:
                currNode.next=currNode.next.next;
                break
            else:
                currNode=currNode.next
            
ll=linkList()
ll.addFirst(1)
ll.addFirst(2)
ll.addFirst(3)
ll.addFirst(4)
ll.showLL()
ll.deleteNum(4)
ll.showLL()