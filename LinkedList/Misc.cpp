#include <iostream>
using namespace std;
#include "Node.cpp"

void EvenAfterOdd(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node *prev = NULL;
        Node *current = head;
        Node *after = current->next;
        while(current!=NULL){
            if(((current->data)%2==0) && ((after->data)%2!=0)){
                after->next=current;
                prev->next=after;
                current->next=after->next;
            } 
            prev=prev->next;
            current=current->next;
            after=after->next;
        }
        temp=temp->next;
    }
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
// Append last N node to first
// Node* appendLast(Node* head,int n,int len){
//     Node* temp = head;
//     for(int i=1;i<len-n;i++){
//         temp = temp->next;
//     }
//     temp->next=NULL;
// }

int main(){
    Node* head = takeInput_Better();
    print(head);
    EvenAfterOdd(head);
    print(head);
}