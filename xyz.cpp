#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	while(cin){
		vector<int> arr;
		while(cin.peek()!='\n'){
		int x;
		cin>>x;
		arr.push_back(x);
		}
	}
	

	int  l = arr[arr.size()-1];
	arr.pop_back();
	sort(arr.begin(),arr.end());
	int n=0;    
	int left = 0;
	int right = arr.size()-1;
	while(left<right){
		int residue = l - arr[right];
		while(residue >= arr[left]){
			left++;
			residue-= arr[left];
		}
		n++;
		right--;
	}
	if(right==left)cout<<n+1;
	else cout<<n;
	return 0;
}

