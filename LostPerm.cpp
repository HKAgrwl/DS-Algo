#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	   int n,m;
	   cin>>n>>m;
	   int arr[n];
	   set<int>coolSet;
	   int maxIndex=INT_MIN;
	   for(int i=0; i<n; i++){
	       cin>>arr[i];
	       coolSet.insert(arr[i]);
	   }
	   for(int i=0; i<n; i++){
	       if(maxIndex<arr[i])
	       maxIndex=arr[i];
	   }
	   int num=1;
	   int sum=0;
	   while(num){
	       if(coolSet.find(num)!=coolSet.end()){
	           num++;
	           continue;
	       }
	       sum+=num;
	       if(sum>m){
	           cout<<"NO"<<endl;
	           break;
	       }
	       coolSet.insert(num);
	       if(sum==m){
	           int temp=0;
	           for(int k=1; k<=maxIndex; k++){
	               if(coolSet.find(k)!=coolSet.end())
	               continue;
	               temp=1;
	               break;
	           }
	           if(!temp) cout<<"YES"<<endl;
	           else cout<<"NO"<<endl;
	           break;
	       }
	       num++;
	   }
	}
	return 0;
}