#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};

void insertAtTail(Node* &head,int value){
    
    if(head==NULL){
        head=n;
        return;
    }
    Node* n = new Node(val)
    ;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void deletions(Node* &head,int val){
        Node* temp = head;
        while(temp->next->data!=val){
            temp=temp->next;
        }
        Node todelete = temp->next;
        temp->next = temp->next->next;

        delete todelete;

    }

void display(Node* head){
    Node* temp=head;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    insertAtTail(head,1);   
    insertAtTail(head,2);
    insertAtTail(head,3);
    deletions(head,3);
    display(head);
    return 0;
}
