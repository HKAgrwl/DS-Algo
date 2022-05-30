#include <iostream>
#include <climits>
using namespace std;


// Stacks os an abstract datatype
class StackUsingArray{
    int* data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity= totalSize;
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
            cout<<"Stack overflow"<<endl;
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