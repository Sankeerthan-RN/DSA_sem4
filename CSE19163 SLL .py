class SLList():
    class node:
        def __init__(self,data):
            self.element = data
            self.next = None

 

    def __init__(self):
        self.head = self.node(None)
        self.sz = 0
        
    def insertFirst(self,data):
        temp = self.node(data)
        
        if(self.head.next==None):
            self.head.element = data;
        else:
            temp.next = self.head
            self.head = temp

 

        return
    
    def insertLast(self,data):
        
        node = self.node(data)
        if(self.head.next == None):
            self.head = node
        else:
            curr = self.head
            while(curr.next!=None):
                curr = curr.next
            curr.next = node
        
        return
    
    def deleteFirst(self):
        node = self.head
        self.head = self.head.next
        del node
        
        return

 

    def deleteLast(self):
        temp = self.head
        while(temp):
            prev = temp
            temp = temp.next
        prev.next = None   
        del temp
        return
    
    def isEmpty(self):

 

        if(self.head.element == None): return True
        return False
        
    def listSize(self):
        
        node = self.head;
        if(self.isEmpty()): return 0
        self.sz = 1
        
        while node.next!=None:
            self.sz+=1
            node = node.next
        return self.sz
    
    def printList(self):
        if (self.isEmpty()):
            print("List is Empty")
        else:
            currentNode = self.head
            while(currentNode != None):
                print(currentNode.element, end =" ")
                currentNode = currentNode.next
            print("")

 

def testSLL():
    sll = SLList()
    inputs=int(input())
    while inputs>0:
        command=input()
        operation=command.split()
        if(operation[0]=="S"):
            print(sll.listSize())
        elif(operation[0]=="I"):
            print(sll.isEmpty())
        elif(operation[0]=="IF"):
            sll.insertFirst(int(operation[1]))
            sll.printList()
        elif(operation[0]=="IL"):
            sll.insertLast(int(operation[1]))
            sll.printList()
        elif(operation[0]=="DF"):
            sll.deleteFirst()
            sll.printList()
        elif(operation[0]=="DL"):
            sll.deleteLast()
            sll.printList()
        inputs-=1

 

def main():
    testSLL()

 

if __name__ == '__main__':
    main()