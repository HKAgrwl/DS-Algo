#include <iostream>
using namespace std;

int main()
{
    string x;
    cin>>x;
    string ans = "";
    for(int i=0;i<x.size();i++){
        if(i+2<x.size() && x[i]=='W' && x[i+1]=='U' && x[i+2]=='B'){
            i+=2;
            if(ans.size()!=0) ans+=' ';
            continue;
        }
        ans+=x[i];
    }
    cout<<ans;
    return 0;
}
