#include <iostream>
#include<vector>
using namespace std;

bool myCompare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    for(auto element:v){
        cout<<element<<endl;
    }

    v.pop_back(); //deletes the last added elemnt from the vector

    vector<int> v2 (3,50);
    // output vector: 50 50 50

    swap(v,v2);//swaps the values of va nd v2 at each corrsponding index.

    // sort(v.begin(),v.end());

    // Pairs
    // pair<int,char> p;
    // p.first = 3;
    // p.second = 'd';

    // Question: Reduding array
    int arr[] = {10,16,7,14,5,3,2,9};

    vector <pair<int,int>> v3;
    for(int i=0;i<sizeOf(arr)/sizeOf(arr[0]);i++){
        // v.push_back(make_pair(arr[i],i))
        pair<int,int> p;
        p.first = arr[i];
        p.second =i;
        v3.push_back(p);
    }
    sort(v3.begin(),v3.end(),myCompare);
    for (int  i = 0; i < v3.size(); i++)
    {
        /* code */
        arr[v3[i].second] = i;
    }
    for (int  i = 0; i < v3.size(); i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
