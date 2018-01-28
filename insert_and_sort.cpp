#include <iostream>

using namespace std;
struct Node {
       int data;
       Node* next;
   };
Node* head = NULL;
Node* tail = NULL;

void insertHead(int data) {
    Node* n = new Node();
    n->data = data;
    Node* temp = head;
    
    if (head == NULL){ //set first element added as tail
        tail = n;
    }
    
    head = n;
    n->next = temp;
    

}

void printAll(Node* n){
    if(n->next == NULL){
        printf("%d", n->data);
        return;
    }
    printf("%d", n->data);
    printAll(n->next);
}

void insertTail(int data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL; //tail always points to NULL
    
    if(tail!=NULL) { //if list is not empty
        Node* temp = tail;
        temp->next = n;
        tail = n;
    }
    else {
        tail = n;
        head = n;
    }
}

int main()
{
   cout << "Hello World\n123\n" << endl; 
   insertHead(4);
   insertHead(3);
   insertHead(2);
   insertHead(1);
   
   insertTail(5);
   insertTail(6);
   insertTail(7);
   insertTail(8);
   
   printAll(head);
   return 0;
}