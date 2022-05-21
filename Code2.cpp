#include <iostream>
using namespace std;
#include "./LinkedList/Node.cpp"

Node* deleteNode(Node* head,int i){
    int count=0;
    Node* temp=head;
    if(i==0){
        head = head->next;
        return head;
    }
    while(count<i-1 && temp->next->next!=NULL){
        temp = temp->next;
        count++;
    }
    Node* a = temp->next->next;
    delete( temp->next);
    temp->next=a;
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

Node* inputLL(){
    int data;
    cin>>data;
    int count=0;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
        count++;
    }
    cout<<count;
    return head;
}

int main()
{
    Node* head = inputLL();
    print(head);
    cout<<endl;
    int i;
    cin>>i;
    head = deleteNode(head,i);
    print(head);
    return 0;
}
