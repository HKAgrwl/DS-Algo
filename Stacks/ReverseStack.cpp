#include <iostream>
using namespace std;
#include "UsingArray.cpp"
// using inbuilt stack
// #include <stack>
 StackUsingArray St;
 StackUsingArray x;


// code to reverse a stack using only one extra stack
void reverseStack(){
    if(x.isEmpty()){
        return;
    }
    int a = x.top();
    x.pop();
    reverseStack();
    St.push(a);
}

void interim(){
    if(St.isEmpty()){
        reverseStack();
        return;
    }
    x.push(St.top());
    St.pop();
    interim();
}

int main(){
    int size;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        int t;  
        cin>>t;      
        St.push(t);
    }
    cout<<St.top()<<endl;
    interim();
    cout<<St.top()<<endl;
    St.pop();
    cout<<St.top()<<endl;
    St.pop();
    cout<<St.top()<<endl;
    St.pop();
    cout<<St.top()<<endl;
    St.pop();
}