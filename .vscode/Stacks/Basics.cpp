#include <iostream>
using namespace std;
#include "UsingArray.cpp"

int main()
{
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(70);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}
