#include <iostream>
using namespace std;
#include <unordered_map>


int main()
{
    unordered_map<string,int> ourMap;
    ourMap["abc"] = 1; 
    ourMap["abc2"] = 2; 
    ourMap["abc3"] = 3; 
    ourMap["abc4"] = 4; 
    ourMap["abc5"] = 5; 

    unordered_map<string,int> :: iterator it = ourMap.begin();
    while(it!=ourMap.end()){
        cout<<"Key:"<<it->first<<" Value:"<<it->second<<endl;
        it++;
    }

    // find
    unordered_map<string,int>::iterator it2= ourMap.find("abc");
     
    return 0;
}
