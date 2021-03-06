#include <iostream>
#include <climits>
using namespace std;


// Stacks os an abstract datatype
class StackUsingArray{
    int* data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity= 4;
    }

    // return the number of elemnts present in the class
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    // insert element
    void push(int element){
        if(nextIndex==capacity){
            // cout<<"Stack overflow"<<endl;
            int* newData = new int[capacity*2];
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

    // delete element
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex]; 
    }

    // access topmost element
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};