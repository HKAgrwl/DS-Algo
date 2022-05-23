#include <iostream>
using namespace std;
#include "Node.cpp"

Node* merge(Node* head1, Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* head = NULL;
    Node* temp = NULL;
    if(head1->data>head2->data){
        head = head1;
    }else{
        head=head2;
    }
    while(temp1 !=NULL || temp2 !=NULL){
        if(temp1->data<temp2->data){
            Node* newNode = new Node(temp1->data);
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }else{
            Node* newNode = new Node(temp2->data);
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    return head;
}
Node* takeInput_Better(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1){
        // Node n(data); We nedd to dynamically allocate our each new node
        Node *newNode = new Node(data);
        if(head==NULL){
              head=newNode;
              tail=newNode;
        }else{
            tail->next=newNode;
            tail= tail->next;
            // OR
            // tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head1 = takeInput_Better();
    Node* head2 = takeInput_Better();
    Node* head= merge(head1,head2);
    print(head);
    return 0;
}
