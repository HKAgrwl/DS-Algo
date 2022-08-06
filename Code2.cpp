#include <iostream>
using namespace std;
#include <unordered_map>

int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> visit;
        int left=0;
        int right=0;
        int res=0;
        while(right<s.length()){
			char r = s[right];
            while(!visit[r] && right<s.length()){
                visit[r]=true;
                right++;
				r=s[right];
            }
            res = max(res,right-left);
			char l = s[left];
            while(visit[r]){
                visit[l]=false;
                left++;
				l=s[left];
            }
        }
        return res;
    }

void pattern(int n){
	int j;
	int k;
	k=n;
	while(k>0){
		j=n;
		while(j>0){
			cout<<j;
			j--;
		}
		cout<<endl;
		k--;
	}
}

int main()
{
	string t;
	cin >> t;
	cout<<lengthOfLongestSubstring(t);
	// for (int i = 0; i < t; i++)
	// {
	// 	int n, k;
	// 	cin >> n >> k;
	// 	int arr[n];
	// 	for (int j = 0; j < n; j++)
	// 		cin >> arr[i];
	// 	int distinctFlav = 0;
	// 	int l = 0, r = 0;
	// 	int ans;
	// 	int max = 0;
	// 	while (l < n)
	// 	{	
	// 		ans=0;
	// 		distinctFlav=0;
	// 		r=l+1;	
	// 		while (r < n && distinctFlav < k)
	// 		{
	// 			if (arr[r] != arr[r - 1])
	// 			{
	// 				distinctFlav++;
	// 			}
	// 			ans++;
	// 			r++;
	// 		}
	// 		if (ans > max)
	// 		{
	// 			max = ans;
	// 		}
	// 		l++;
	// 	}
	// 	cout<<max<<endl;
	// }
	return 0;
}
