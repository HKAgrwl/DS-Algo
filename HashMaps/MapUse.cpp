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

int diffK(int* arr,int size,int k){
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        m[arr[i]]++;
    }
    int count=0;
    for(int i=0;i<size;i++){
        count+=m[arr[i]+k]*m[arr[i]];
        count+=m[arr[i]-k]*m[arr[i]];
        m[arr[i]]=0;
    }
    return count;
}

pair<int,int> Longestsubseq(int* arr,int size){
    pair<int,int> p;
    p.first = p.second = 0;
    unordered_map<int,int> m;
    for(int i=0;i<size;i++){
        m[arr[i]]++;
    }
    int j,len,max,start,end;
    len=max=1;
    j=1;
    for(int i=0;i<size;i++){
        while(m.count(arr[i]+j)>0){
            len++;
            j++;
        }
        end = arr[i]+j-1;
        j=1;
        while(m.count(arr[i]-j)>0){
            len++;
            j++;
        }
        start = arr[i]-j+1;
        if(len>max){
            max=len;
            p.first= start;
            p.second = end;
        }
    }
    return p;
}

int zeroSum(int* arr,int size){
    unordered_map<int,int> hashmap;
    int max,len,sum;
    max=len=sum=0;
    for(int i=0;i<size;i++){
        sum+= arr[i];
        if(hashmap[sum] > 0){
            len = i - hashmap[sum] + 1;
            if(len>max){
                max=len;
            }
            continue;
        }
        hashmap[sum]=i+1;
    }
    return max;

}

int main()
{
    // int a[] = {1,2,3,3,2,1,4,3,6,5,5};
    // vector<int> output = removeDuplicate(a,11);
    // for(int i=0;i<output.size();i++){
    //     cout<<output[i]<<endl;
    // }
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // cin>>k;
    // cout<<diffK(arr,n,k);
    // pair<int,int> p = Longestsubseq(arr,n);
    // cout<<p.first<<" "<<p.second;
    cout<<zeroSum(arr,n);
    return 0;
}
