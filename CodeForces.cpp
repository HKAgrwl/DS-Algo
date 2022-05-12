#include <iostream>
using namespace std;

int Lcm(int a,int b,int p){
    if(b%a==0){
        return b;
    }
    return Lcm(a,b+p,p);
}

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b){
        cout<<Lcm(b,a,a);
    }else{
        cout<<Lcm(a,b,b);
    }
    return 0;
}
