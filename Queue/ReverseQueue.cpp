#include <iostream>
using namespace std;
#include "UsingArrays.cpp"
QueueUsingArrays<int> q(4);

void reverseQueue(int size){
    if(size==0){
        return;
    }
    int a = q.top();
    q.deQueue();
    reverseQueue(size-1);
    q.enQueue(a);
}

int main()
{
    int size;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin>>x;
        q.enQueue(x);
    }
    cout<<q.top()<<endl;
    reverseQueue(4);
    cout<<q.top()<<endl;
    q.deQueue();
    cout<<q.top()<<endl;
    q.deQueue();
    cout<<q.top()<<endl;
    q.deQueue();
    cout<<q.top()<<endl;
    q.deQueue();
    cout<<q.top()<<endl;
    return 0;
}
