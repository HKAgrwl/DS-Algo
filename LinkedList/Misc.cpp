#include <iostream>
using namespace std;

// Append last N node to first
Node* appendLast(Node* head,int n,int len){
    Node* temp = head;
    for(int i=1;i<len-n;i++){
        temp = temp->next;
    }
    temp->next=NULL;
}