#include <iostream>
using namespace std;
#include "UsingArray.cpp"
// using inbuilt stack
#include <stack>

int main()
{
    stack<int> s;
    s.push(10);
    s.push(21);
    s.push(54);
    s.push(98);
    s.push(76);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    // StackUsingArray s(4);
    // s.push(10);
    // s.push(20);
    // s.push(40);
    // s.push(70);
    // cout<<s.top()<<endl;
    // cout<<s.pop()<<endl;

    // cout<<s.size()<<endl;
    // cout<<s.isEmpty()<<endl;
    // return 0;
}
