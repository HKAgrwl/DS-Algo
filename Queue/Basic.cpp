#include <iostream>
using namespace std;
// inbuilt Queue
#include <queue>

int main()
{
    queue<int> x;
    x.push(21);
    x.push(45);
    x.push(87);
    cout<<x.front()<<endl;
    x.pop();
    cout<<x.front()<<endl;
    cout<<x.size()<<endl;
    cout<<x.empty()<<endl;
    return 0;
}
