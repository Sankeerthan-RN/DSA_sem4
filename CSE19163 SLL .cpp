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
      temp->element=x;
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
        new_node->next = head;
        head = new_node;
      }
    n++;
        
  
		
		
		
		//@end-editable@
		return x;
	}

	T removeLast() {
	    //@start-editable@

   
		if(n==0){
	        return NULL;
	    }
	       
	       Node *curr = head;
           Node *prev;
           curr = head;
           while(curr->next!=NULL)
         {
          prev = curr;
          curr = curr->next;	
         }
         tail=prev;
         prev->next=NULL;
         delete curr;
           T x;
           n--;
	    if(1==1)
		{
		
		         
			//@end-editable@
			return x;
		}
		
	}

	T removeFirst() {
	    //@start-editable@

    
	    
	    
	        Node* temp = head; 
            head = head->next; 
            delete temp;
            n--;
	        
	    
		
		
		 T x;
		
		//@end-editable@
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