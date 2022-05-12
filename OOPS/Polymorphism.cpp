#include <iostream>
using namespace std;

// function overloading
class JhatuCollege{
    public:
    void func(){
        cout<<"I am a jhatu function with no arguments"<<endl;
    }
    void func(int x){
        cout<<"I am a function with an integer argument"<<endl;
    }
};

// operator overloading
class Complex{
    private:
    int real;
    int imag;
    public:
    Complex(int r,int i){
        real=r;
        imag=i;
    }

    Complex operator + (Complex const &obj){
        Complex res;
        res.imag = imag + obj.imag;
        res.real = real+ obj.real;
        return res;
    }

    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }
};

int main()
{
    JhatuCollege obj;
    obj.func();
    obj.func(4);
    Complex c1(12,7);
    Complex c2(6,7);
    Complex c3 = c1+c2;
    c3.display();

    return 0;
}
