#include <iostream>
using namespace std;
#include "Node.cpp"

void EvenAfterOdd(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node *prev = new Node(0);
        Node *current = head;
        prev->next=current;
        Node *after = current->next;
        while(after!=NULL){
            if(((current->data)%2==0) && ((after->data)%2!=0)){
                // cout<<prev->data<<endl; 
                // cout<<current->data<<endl;
                // cout<<after->data<<endl;
                Node* a = after->next;
                after->next=current; 
                prev->next=after;
                current->next=a;
                prev=after;
                after = current->next;
                // cout<<prev->data<<endl;
                // cout<<current->data<<endl;
                // cout<<after->data<<endl;
            }else{
                prev=prev->next;
                current=current->next;
                after=after->next;
                // cout<<prev->data<<endl;
                // cout<<current->data<<endl;
                // cout<<after->data<<endl;
            }
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
Node* func(Node* head,int value){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    while(head!=NULL){
        if(head->data <  value){
            if(head1==NULL){
                head1 = head;
                tail1 = head1->next;
            }else{
                tail1 = head;
                tail1 = tail1->next;
            }
            head = head->next;
        }else{
            if(head2==NULL){
                head2 = head;
                tail2 = head2->next;
            }else{
                tail2 = head;
                tail2 = tail2->next;
            }
        }
    }
    tail1->next = head2;
    return head1;
}


int main(){
    Node* head = takeInput_Better();
    print(head);
    EvenAfterOdd(head);
    print(head);
}

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    getline(cin,str);
    int len = str.length();
    for(int i=0;i<len;i++){
        int count=0;
        int valid=1;
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            valid=0;
        }
        if(str[i] ==' ' && valid == 1){
            count++;
        }
    }
    cout<<count;
    return 0;

    