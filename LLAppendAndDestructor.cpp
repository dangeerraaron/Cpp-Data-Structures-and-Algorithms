#include <iostream>

using namespace std;

class Node{
	
	public:

	    int value;
	    Node *next;
	    //contstuctor for node
	    Node(int value){
	    	this -> value = value;
	    	next = nullptr;
	    }
	
};

class LinkedList{
	private: //fields
	    Node* head;
	    Node* tail;
	    int length;
	    
	  public: //linkedList constructor
	      LinkedList(int value){
	      	Node* newNode = new Node(value);
	      	head = newNode;
	      	tail = newNode;
	      	length = 1;
	      }
	      
          ~LinkedList(){ //linked list destructor
              Node* temp = head;
              while(head != nullptr){
                  head = head->next;
                  delete temp;
                  temp = temp->next;
              }
          }
	      void printList(){
	      	Node* temp = head;
	      	while(temp != nullptr){
	      		cout << temp->value <<endl;
	      		temp = temp->next;
	      	}
	      	
	      }
	      
	      void getHead(){
	      	cout << "Head: " << head->value << endl;
	      }
	     
	     void getTail(){
	     	cout << "Tail: " << tail->value << endl;
	      }
	    
	    void getLength(){
	         cout << "Length: " << length << endl;
	      }

        void append(int value){ 
            
            Node* newNode = new Node(value);

            if(length == 0){
                
                head = newNode;
                
                tail = newNode;
            }else{
                
                tail->next = newNode;
                tail = newNode;
            }

            length++;
        }   
};

int main( void){
	
	LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->printList();
	
	myLinkedList->getHead();
	myLinkedList->getTail();
	myLinkedList->getLength();
	
}