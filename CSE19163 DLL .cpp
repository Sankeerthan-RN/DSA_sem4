
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
		Node *prev;
		Node(T x) {
		    //@start-editable@
         this->prev =NULL;
         this->next =NULL;
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
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
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
        new_node->prev =NULL;
        head->prev=new_node;
        new_node->next = head;
        
        head = new_node;
      }
    n++;
        
  
		
		
		
		//@end-editable@
		return x;
	}
	
	

	T removeLast() {
	    //@start-editable@

            T x;
		if(n==0){
	        return x;
	    }
	    if(n==1)
	    {
	        
	        delete head,tail;
	        n--;
	        return x;
	        
	    }
	       
	     Node *temp=tail;
	     tail=tail->prev;
	     tail->next=NULL;
	     delete temp;
	     n--;
	     return x;
		
		
	}

	T removeFirst() {
	    //@start-editable@
	    T x;
	    	if(n==0){
	        return x;
	            }
	        if(n==1)
	        {
	           delete head,tail;
	           n--;
	           return x;
	        }
	        Node* temp = head; 
            head = head->next;
            head->prev =NULL;
            delete temp;
            n--;
		    
		
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
	    new_node->prev=temp;
	    after->prev=new_node;
	    new_node->next=after;
	    n++;
	   
	   }
	 return value;
	    
	}
	T insertBefore( T pos ,T value){
	     
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
	    cout<<temp->element<<endl;
	    if(temp->prev==NULL){
	        insertFirst(value);
	        return value;
	    }
	    Node *new_node=new Node(value);
	    Node * before =temp->prev;
	    cout<<before->element<<endl;
	    before->next=new_node;
	    new_node->prev=before;
	    temp->prev=new_node;
	    new_node->next=temp;
	    
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
	        if(temp->next== NULL)
	        {
	            return x;
	        }
	    }
	    if(temp->next->next==NULL)
	    {
	       removeLast();
	       return x;
	    }
	    Node *after =temp->next->next;
	    temp->next=after;
	    after->prev=temp;
	    n--;
	    return x;
	}
	T deleteBefore( T u)
	{
	  T x;
	  if(n==0|| n==1 )
	  {
	      return x;
	      
	  }
	   Node *temp =head;
	   
	   while(temp->element!=u)
	    {   
	        temp=temp->next;
	    }
	    
	    if(temp->prev->prev==NULL)
	    {
	        removeFirst();
	        return x;
	    }
	    Node *before =temp->prev->prev;
	    before->next=temp;
	    temp->prev=before;
	    n--;
	   return x;
	}
	
	
	

	
	  
	
//Prints the list
	void printlist(){
		if (!isEmpty()) {
			Node *temp = head;
			while (temp != NULL) {
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
 	   
 	    else if (str.substr(0, 1) == "S"){
 	       cout<< slist1.size()<<endl;
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