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

void reverse_iterative(){
    Node* current_node = head;
    Node* prev_node = NULL;
    Node* next_node = NULL; 

    while(current_node->next != NULL) {
        next_node = current_node->next; //save next node
        current_node->next = prev_node; //Link current node to prev
        
        prev_node = current_node; //shift focus to next node
        current_node = next_node; //shift focus to next node
    }
    current_node->next = prev_node; //Connect the last node
    head = current_node;
    return;
}

void reverse_recursive(Node* c){
    Node* next_node = NULL;
    
    if(c->next == NULL) {
        head = c;
        return;
    }
    reverse_recursive(c->next);
    next_node = c->next;
    next_node->next = c;
    c->next = NULL;
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
   printf("\n");
   reverse_iterative();
   printAll(head);
   printf("\n");
   reverse_recursive(head);
   printAll(head);
   return 0;
}