#include <iostream>
using namespace std;
#include "Node.cpp"

// Indert a node at the ith position of the linked list
Node* insertNode(Node *head,int i,int data){
    Node* newNode = new Node(data);
    int count=0;
    Node *temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }

    while(count<i-1 && temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        Node* a= temp->next;
        temp->next = newNode;
        newNode->next=a;    
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
    Node* head = takeInput_Better();
    print(head);
    int i,data;
    cin>>i>>data;
    head=insertNode(head,i,data);
    print(head);
    return 0;
}
