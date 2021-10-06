
#include <iostream>
#include<string>
using namespace std;

template<class T>
class SLList {
protected:
	class Node {
	public:
		T element;
		Node *next;
		Node(T x) {
		    //@start-editable@

         this->element = x;			
			
			//@end-editable@
		}
	};
	Node *head;
	Node *tail;
	int n;

public:
	SLList() {
		n = 0;
		head = tail = NULL;
	}

	bool isEmpty(){
		//@start-editable@

    if(head ==NULL)
    {
        return  true;
    }
    return false;
    
		
		
		
		//@end-editable@
	}

	int size() {
	    //@start-editable@

      
        return n;
	    
	    //@end-editable@
	}

	bool insertLast(T x) {
	    //@start-editable@

      Node *temp = new Node(x);
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
        temp->next=head;
      }	
	n++;	
		
		//@end-editable@
		return true;
	}

	T insertFirst(T x) {
	    //@start-editable@

    Node *new_node = new Node(x);
     if (n==0)
    {
        head = new_node;
        tail = head;
    }
      else
      {
        Node *temp=head;
        new_node->next = head;
        head = new_node;
        tail->next=head;
      }
    n++;
        
  
		
		
		
		//@end-editable@
		return x;
	}

	T removeLast() {
	    //@start-editable@

        T x;
		if(n==0){
	        return NULL;
	    }
	    if (head == NULL) {
        
        return x;
        }
       
 
          Node *curr = head;
          Node *before;
          if (curr->next == curr) 
          {
            head = NULL;
            return x;
          }
	       
	      
          while (curr->next != head) 
          {
                before = curr;
                curr = curr->next;
          }
          before->next=head;
          tail =before;
         
         
         
        
       
	      //@end-editable@
		   return x;
		
		
	}

	T removeFirst() {
	    //@start-editable@
	        Node* temp=head;
	        tail->next=temp->next ;
	        head=temp->next;
            delete temp;
            n--;
	        T x;
		
		//@end-editable@
		return x;
	}
	 T insertAfter( T pos ,T value){
	     
	    
	    Node *temp=head;
	   if(n!=0){
	    while(temp->element!=pos )
	    {
	       
	        temp=temp->next;
	        if(temp==NULL)
	        {
	            return value;
	        }
	    }
	    if(temp->next==NULL){
	        insertLast(value);
	        return value;
	    }
	    Node *new_node=new Node(value);
	    Node * after =temp->next;
	    temp->next=new_node;
	    new_node->next=after;
	    n++;
	   
	   }
	 return value;
	    
	}
	T insertBefore( T pos ,T value){
	     
	   Node *before=head;
	   if(before->element ==pos)
	   {
	       insertFirst(value);
	       return value;
	   }
	   if(n!=0){
	    while(before->next->element!=pos )
	    {
	        
	        before=before->next;
	        
	        if(before->next==NULL)
	        {
	            return value;
	        }
	    }
	   
	    Node *new_node=new Node(value);
	    Node *temp=before->next;
	    before->next=new_node;
	    new_node->next=temp;
	    
	    n++;
	    
	    
	    
	   }
	   return value;
	    
	}
	T deleteAfter( T u)
	{
	    T x;
	    if(n==0 ||n==1)
	    {
	        return x;
	    }
	    Node *temp =head;
	    while(temp->element!=u)
	    {   
	        temp=temp->next;
	        if(temp->next==head)
	        {
	            return x;
	        }
	    }
	    if(temp->next->next==head)
	    {
	       removeLast();
	       return x;
	    }
	    Node *after =temp->next->next;
	    temp->next=after;
	    n--;
	    return x; 
	}
	T deleteBefore( T u)
	{
	    T x;
	    if(n==0 ||n==1)
	    {
	        return x;
	    }
	    Node *temp =head;
	    Node *before=head;
	    while(temp->next->element!=u)
	    {   
	        before=temp;
	        temp=temp->next;
	        if(temp->next==head)
	        {
	            return x;
	        }
	    }
	    if(before==head)
	    {
	        
	        removeFirst();
	        return x;
	    }
	    
	    before->next=temp->next;
	    n--;
	    return x; 
	}
	
//Prints the list
	void printlist(){
		if (!isEmpty()) {
			Node *temp = head;
			while (temp != NULL) {
			    if(temp->next==head)
			    {
			        cout << temp->element <<endl;
			        return;
			    }
				cout << temp->element << " ";
				temp = temp->next;
			}
			cout << endl;
			return;
		}
		cout << ("List is empty!")<<endl;
	}

};

//Driver Code
int main(){
	SLList<int> slist1;
 	string noOfInputs,str;
 	getline(cin, noOfInputs);
 	for(int i=0;i<stoi(noOfInputs);i++){
 	    getline(cin, str); 
 	    
 	    if (str.substr(0, 2) == "IF"){
 	        int value = stoi(str.substr(3, 5));
 	        slist1.insertFirst(value);
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IL"){
 	        int value = stoi(str.substr(3, 5));
 	        slist1.insertLast(value);
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DF"){
 	        slist1.removeFirst();
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DL"){
 	        slist1.removeLast();
 	        slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IA"){
 	         int value = stoi(str.substr(3, 2));
 	         int pos= stoi(str.substr(5, 2));
 	         slist1.insertAfter(value,pos);
 	         slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IB"){
 	         int value = stoi(str.substr(3, 2));
 	         int pos= stoi(str.substr(5, 2));
 	         slist1.insertBefore(value,pos);
 	         slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DA"){
 	         int value = stoi(str.substr(3, 5));
 	         slist1.deleteAfter(value);
 	         slist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DB"){
 	         int value = stoi(str.substr(3, 5));
 	         slist1.deleteBefore(value);
 	         slist1.printlist();
 	    }
 	    
 	    else if (str.substr(0, 1) == "S"){
 	       cout<< slist1.size()<<endl;
 	    }
 	    else if (str.substr(0,1) == "I"){
 	        //cout<<slist1.isEmpty()<<endl;
 	        if(slist1.isEmpty()){
 	            cout<<"True"<<endl;
 	        }
 	        else{
 	            cout<<"False"<<endl;
 	        }
 	    }
 	}
}