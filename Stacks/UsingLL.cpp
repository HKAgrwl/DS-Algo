#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next=NULL;
    }
};

class StackUsindLL{
    Node* head;
    int size;
    
    public:
    StackUsindLL(){
        head=NULL;
        size=0;
    }
    void push(int element){
        Node* newNode = new Node(element);
        newNode->next =head;
        head= newNode;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is empty";
        }
        Node* a = head;
        head= head->next;
        free(a);
        size--;
    }

    int getSize(){
        return size;
    }
    int top(){
        if(head==NULL){
            cout<<"Empty stack";
            return 0;
        }
        return head->data;
    }
};

// int main()
// {
//     StackUsindLL s;
//     s.push(30);
//     s.push(22);
//     s.push(72);
//     cout<<s.getSize()<<endl;
//     s.pop();
//     cout<<s.getSize()<<endl;
//     cout<<s.top()<<endl;
//     return 0;
// }
