#include <iostream>

using namespace std;
struct Node {
       int data;
       Node* next;
   };
Node* head = NULL;

void insertHead(int data) {
    Node* n = new Node();
    n->data = data;
    Node* temp = head;
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


int main()
{
   cout << "Hello World\n123\n" << endl; 
   insertHead(4);
   insertHead(3);
   insertHead(2);
   insertHead(1);
   
   
   printAll(head);
   return 0;
}