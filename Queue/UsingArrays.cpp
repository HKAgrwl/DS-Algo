#include <iostream>
using namespace std;
template <typename T>

class QueueUsingArrays{
    T* data;
    int first;
    int nextIndex;
    int capacity;

    public:
    QueueUsingArrays(int size){
        data = new T[size];
        first=0; 
        nextIndex=0;
        capacity = size;
    }
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return first>=nextIndex;
    }
    void enQueue(T element){
        if(nextIndex==capacity){
            cout<<"Stack Overflow";
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    void deQueue(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        first++;

    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[first];
    }
};

int main()
{
    QueueUsingArrays<int> q(4);
    q.enQueue(32);
    q.enQueue(72);
    q.enQueue(43);
    q.enQueue(96);
    q.deQueue();
    cout<<q.top()<<endl;
    q.deQueue();
    q.deQueue();
    cout<<q.isEmpty()<<endl;
    q.deQueue();
    cout<<q.isEmpty()<<endl;
    return 0;
}
