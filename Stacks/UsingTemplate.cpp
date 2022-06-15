#include <iostream>
using namespace std;
template <typename T>

class StackUsingTemplate{
    T* data;
    int nextIndex;
    int capacity;

    public:
    StackUsingTemplate(){
        data = new T[4];
        nextIndex=0;
        capacity=4;
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    void push(T element){
        if(nextIndex==capacity){
            T* newData = new T[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i]=data[i];

            }
            capacity*=2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex]; 
    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};


int main()
{
    StackUsingTemplate<char> s;
    s.push(100);//this integer is now treated as an ASCII value.
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    // cout<<s.size()<<endl;
    return 0;
}
