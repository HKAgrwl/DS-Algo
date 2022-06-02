#include <iostream>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node* next;

    Node(T value){
        data=value;
        next=NULL;
    }
};

class QueueUsingLL{
    Node* head;
    Node* tail;
    int size;

    public:
    QueueUsingLL(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enQueue(T data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=head;
        }else{
            tail->next = newNode;
            tail=tail->next;
            size++;
        }
    }
    void deQueue(){
        if(isEmpty()){
            cout<<"Queue is empty";
        }else{
            Node* temp = head;
            head=head->next;
            size--;
            delete(temp);
        }

    }
    T top(){
        if(isEmpty()){
            cout<<"Queue id empty";
            return 0;
        }
        return head->data;
    }

};

T main()
{
    
    return 0;
}
