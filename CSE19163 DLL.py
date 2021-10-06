class SLList():
    # @start-editable@
    class node:
        def __init__(self, data):
            self.element = data
            self.next = None
            self.prev = None

    def __init__(self):
        self.head = self.node(None)
        self.tail = self.node(None)
        self.sz = 0

    def insertLast(self, data):
        # @start-editable@
        new_node = self.node(data)
        if (self.sz==0):
            self.head = new_node
            self.tail = self.head

        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
            # @end-editable@
        self.sz = self.sz + 1

        return


    def insertFirst(self, data):
        # @start-editable@
        new_node =self.node(data)
        if (self.sz == 0):
            self.head = new_node
            self.tail = self.head
        else:
            new_node.prev = None
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node


            # @end-editable@

        self.sz=self.sz+1
        return


    def deleteFirst(self):
        # @start-editable@
        if (self.sz == 0):
            return
        if (self.sz == 1):
             self.head=None
             self.tail=None
             self.sz=self.sz-1
             return

        self.head = self.head.next
        self.head.prev = None
        self.sz =self.sz -1
        return

    def deleteLast(self):
        if(self.sz==0):
            return
        if(self.sz==1):
            self.head = None
            self.tail = None
            self.sz = self.sz - 1
            return

        self.tail=self.tail.prev
        self.tail.next=None
        self.sz = self.sz - 1
        return
    def insertAfter(self,lval,newval):

        temp=self.head
        if(self.sz!=0):
            while(temp.element!=lval):
                temp=temp.next
                if(temp==None):
                    return False
            if(temp.next==None):
                self.insertLast(newval)
                return True

            new_node=self.node(newval)
            after=temp.next
            temp.next=new_node
            new_node.prev=temp
            after.prev=new_node
            new_node.next=after
            self.sz=self.sz+1
            return True
    def insertBefore(self,lval,newval):
        temp=self.head
        if(self.sz!=0):
            while(temp.element!=lval):
                temp=temp.next
                if(temp==None):
                    return False
            if(temp.prev==None):
                self.insertFirst(newval)
                return True
            new_node =self.node(newval)
            before=temp.prev
            before.next=new_node
            new_node.prev=before
            temp.prev=new_node
            new_node.next=temp
            self.sz = self.sz + 1
            return True
    def deleteAfter(self,lval):
        if(self.sz==0 or self.sz==1):
            return False
        temp= self.head
        while(temp.element!=lval):
            temp=temp.next
            if(temp.next==None):
                return False
        if(temp.next.next==None):
            self.deleteLast()
            return True
        after=temp.next.next
        temp.next=after
        after.prev=temp
        self.sz = self.sz -1
        return True
    def deleteBefore(self,lval):
        if(self.sz==0 or self.sz==1):
            return False
        temp=self.head
        while(temp.element!=lval):
            temp=temp.next
        
        if (temp.prev == None):
            return False    
        if(temp.prev.prev==None):
            self.deleteFirst()
            return True
        before=temp.prev.prev
        before.next=temp
        temp.prev=before
        self.sz = self.sz-1
        return True













    def isEmpty(self):
        if (self.head == None):
            return True
        return False


    def listSize(self):
        return self.sz


# @end-editable@

    def printList(self):
        if (self.isEmpty()):
            print("List is Empty")
        else:
            currentNode = self.head
            while (currentNode != None):
                print(currentNode.element, end=" ")
                currentNode = currentNode.next
            print("")


# @start-editable@


# @end-editable@

def testSLL():
    sll = SLList()
    inputs = int(input())
    while inputs > 0:
        command = input()
        operation = command.split()
        if (operation[0] == "S"):
            print(sll.listSize())
        elif (operation[0] == "I"):
            print(sll.isEmpty())
        elif (operation[0] == "IF"):
            sll.insertFirst(int(operation[1]))
            sll.printList()
        elif (operation[0] == "IL"):
            sll.insertLast(int(operation[1]))
            sll.printList()
        elif (operation[0] == "DF"):
            sll.deleteFirst()
            sll.printList()
        elif (operation[0] == "DL"):
            sll.deleteLast()
            sll.printList()
        elif (operation[0] == "IA"):
            returnVal = sll.insertAfter(int(operation[1]), int(operation[2]))
            if(returnVal == True):
                sll.printList()
        elif (operation[0] == "IB"):
            returnVal = sll.insertBefore(int(operation[1]), int(operation[2]))
            if (returnVal == True):
                sll.printList()
        elif (operation[0] == "DA"):
            returnVal = sll.deleteAfter(int(operation[1]))
            if (returnVal == True):
                sll.printList()
        elif (operation[0] == "DB"):
            returnVal = sll.deleteBefore(int(operation[1]))
            if (returnVal == True):
                sll.printList()
        inputs -= 1


def main():
    testSLL()


if __name__ == '__main__':
    main()