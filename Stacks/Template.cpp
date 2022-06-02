#include <iostream>
using namespace std;
template <typename T, typename V>

class Pair{
    T x;
    V y;

    public:

    void setX(T x){
        this->x = x;
    }

    T getX(){
        return x;
    }

    void setY(V y){
        this->y = y;
    }

    V getY(){
        return y;
    }
}; 

int main()
{   
    // if there is only one typname and the same is used for both x and y
    // Pair<int> p1;
    Pair<int,double> p;
    Pair<double,double> p2;   
    // Creating a triplet using Pair class
    Pair<Pair<int,int>,int> p3;
    p3.setY(10);
    
    Pair<int,int> p4;//This pair will be used to sed value of first two elements of triplet
    p4.setX(5);
    p4.setY(20);

    p3.setX(p4);
    cout<<p3.getX().getX()<< " "<< p3.getX().getY()<<" "<<p3.getY()<<endl;
    return 0;
}