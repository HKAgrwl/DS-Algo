#include <iostream>
using namespace std;    
#include <map>
// #include <string>

// Map is an associative array
int main()
{
    map<string,int> marks;
    marks['harry']=93;
    marks['Jack']= 98;
    marks['Rohan']= 97;

    marks.insert({{"Harsh",99},{"Akash",87}});

    map<string,int>::iterator itr;
    for(itr==marks.begin();itr!=marks.end();itr++){
        cout<<(*itr).first<<" "<<(*itr).second;
    }
    return 0;
}
