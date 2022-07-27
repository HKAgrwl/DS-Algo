#include <iostream>
using namespace std;
#include <unordered_map>


int main()
{
    unordered_map<string,int> ourMap;
    // inserting
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // find or access
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;
    // cout<<ourMap.at("ghi")<<endl;This gives an eror as "ghi" doea not map to anything.
    cout<<ourMap["ghi"]<<endl;//This creates a new map with "ghi" as id and value as default value i.e 0

    // Check Presence
    if(ourMap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }

    // Get Size
    cout<<"size : "<<ourMap.size()<<endl;

    // erase
    ourMap.erase("ghi");
    return 0;
}
