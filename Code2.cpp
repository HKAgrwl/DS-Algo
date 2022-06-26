#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int j = 0; j < n; j++)
			cin >> arr[i];
		int distinctFlav = 0;
		int l = 0, r = 0;
		int ans;
		int max = 0;
		while (l < n)
		{	
			ans=0;
			distinctFlav=0;
			r=l+1;	
			while (r < n && distinctFlav < k)
			{
				if (arr[r] != arr[r - 1])
				{
					distinctFlav++;
				}
				ans++;
				r++;
			}
			if (ans > max)
			{
				max = ans;
			}
			l++;
		}
		cout<<max<<endl;
	}
	return 0;
}
