#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

vector<int> removeDuplicate(int* a,int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for (int i = 0; i < size; i++)
    {
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    // Alternative
    // for (int i = 0; i < size; i++)
    // {
    //     if(!seen[a[i]]){
    //         output.push_back(a[i]);
    //         seen[a[i]] = true;
    //     }
    // }
    return output;
    
}

int maxFreq(int* arr,int size){
    unordered_map<int,int> count;
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]+=1;
    }
    int max=0;
    int maxElement;
    unordered_map<int,int>::iterator itr;
    for(itr=count.begin();itr!=count.end();itr++){
        if(itr->second > max){
            max = itr->second;
            maxElement=itr->first;
        }
    }
    return maxElement;
    
}

int getPairs(int* arr,int size,int sum){
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        m[arr[i]]++;
    }
    int twice_count=0;
    for(int i=0;i<size;i++){
        twice_count+= m[-arr[i]];
    }
    return twice_count/2;
}

int main()
{
    // int a[] = {1,2,3,3,2,1,4,3,6,5,5};
    // vector<int> output = removeDuplicate(a,11);
    // for(int i=0;i<output.size();i++){
    //     cout<<output[i]<<endl;
    // }
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxFreq(arr,n);
    return 0;
}
