#include <iostream>
using namespace std;
// #include "Node.cpp"
#include "InsertAndDelete.cpp"

//Code to insert a node at ith position of linked list recursively
Node* insertRec(Node* head,int data,int k){
    if(head==NULL){
        return new Node(data);
    }
    if(k==1){
        Node* newNode = new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }else{
        head->next=insertRec(head->next,data,k-1);  
    }
    return head;
}

// Delete the node at ith position recursively
Node* deleteRec(Node* head,int i){
    if(head==NULL){
        return head;
    }
    if(i==0){
        Node* res = head->next;
        delete(head);
        return res;
    }
    else{
        head->next=deleteRec(head->next,i--);
    }
    return head;
}

// remove duplicates
Node* removeDup(Node* head,Node* t1,Node* t2){
    if(t2==NULL){
        t1->next=t2;
        return head;
    }
    if(t2->data==t1->data){
        return removeDup(head,t1,t2->next);
    }else{
        t1->next=t2;
        return removeDup(head,t2,t2->next);
    }
    return head;
}

void printRec(Node* head){
    if(head->next==NULL){
        cout<<head->data<<" ";
        return;
    }
    Node* a = head;
    printRec(head->next);
    cout<<a->data<<" ";
}

Node* reverseRec(Node* head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    Node* smallAns = reverseRec(head->next);
    Node* tail = head->next;
    tail->next=head;
    head->next=NULL:
    return smallAns;
}

// int main()
// {
//     Node* head = takeInput_Better();
//     print(head);
//     // deleteRec(head,2);
//     removeDup(head,head,head);
//     print(head);
//     // printRec(head);
//     return 0;
// }
