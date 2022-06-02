#include <iostream>
using namespace std;
template <typename T>

class QueueUsingArrays{
    T* data;
    int first;
    int nextIndex;
    int size;
    int capacity;

    public:
    QueueUsingArrays(int s){
        data = new T[size];
        first=0; 
        nextIndex=0;
        size=0;
        capacity=s;
    }
    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0 ;
    }
    void enQueue(T element){
        if(size==capacity){
            cout<<"Queue is Full"<<endl;
            return; 
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        size++;
    }

    void deQueue(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }else{
        first = (first+1)%capacity;
        size--;
        if(size==0){
            first= 0 ;
            nextIndex=0;
        }
        }

    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[first];
    }
};

// int main()
// {
//     QueueUsingArrays<int> q(4);
//     q.enQueue(32);
//     q.enQueue(72);
//     q.enQueue(43);
//     q.enQueue(96);
//     q.deQueue();
//     cout<<q.top()<<endl;
//     q.deQueue();
//     q.deQueue();
//     cout<<q.isEmpty()<<endl;
//     q.deQueue();
//     cout<<q.isEmpty()<<endl;
//     return 0;
// }
// Unable to understand circular queue.