#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
#include <vector>
#include <stack>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<int> v;
    int a;
    int len=0;
    while(cin>>a){
        v.push_back(a);
        len++;
    }
    stack<int> interim;
    int ans[len];
    int i=len-1;
    int count;
    vector<int>::iterator it;
    for(it=v.end();it!=v.begin();it--){
        count=0;
        while(!interim.empty() && interim.top() < *it){
            interim.pop();
            count++;
        }
        ans[i]=count;
        interim.push(*it);
        cout<<ans[i]<<endl;
        i--;
    }
    for(int j=0;j<len;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}
