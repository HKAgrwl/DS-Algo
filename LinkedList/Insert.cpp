#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
// inserting at the head
// time complexity is O(n)
void push(Node** head_ref,int new_data){
    // allocate node
    Node* new_node = new Node();
    // put in the data;
    new_node->data=new_data;
    // make next of new node as head
    new_node->next= *head_ref;
    // move thr head to point to the new node;
    *head_ref = new_node;
}

// inserting after a given node
// time complexity of O(n);
void insertAfter(Node* prev_node,int new_data){
    // check if the given prev_node is NULL
    if(prev_node==NULL){
        cout<<"The previous node cannot be NULL";
        return;
    }

    // allocate new node;
    Node* new_node = new Node();
    // put in the data
    new_node->data = new_data;
    // make next of new node as next of prev node
    new_node->next = prev_node->next;
    // move the next of prev node as new node
    prev_node->next= new_node;

}

// adding new node at the end;
// time complexity of O(n);
void append(Node** head_ref,int new_data){
    Node* new_node = new Node();
    // Used in step 5
    Node *last = *head_ref;
    // 2. Put in the data
    new_node->data = new_data; 
     // 3. This new node is going to be 
    // the last node, so make next of 
    // it as NULL
    new_node->next = NULL;
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
     // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next; 
    }
     // 6. Change the next of last node
    last->next = new_node; 
    return; 
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
     
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
     
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);
     
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);
     
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);
     
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
     
    cout<<"Created Linked list is: ";
    printList(head);
    return 0;
}
