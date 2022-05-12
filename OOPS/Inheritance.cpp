#include <iostream>
using namespace std;

class A
{
public:
    void Afunc()
    {
        cout << "FuncA" << endl;
    }
};
class B
{
public:
    void Bfunc()
    {
        cout << "FuncB" << endl;
    }
};
class C : public A, public B
{
public:
};

class Ground
{
    int Rooms;

protected:
    void put();

public:
    void get();
};
class Middle : private Ground
{ //impoorts all public and private properties of the Ground function and stire them as private members of the Middle function.
    int Labs;

public:
    void Take();
    void Give();
};

int main()
{
    C c;
    c.Afunc();
    c.Bfunc();
    return 0;
}
