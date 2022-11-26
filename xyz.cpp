#include <iostream>
using namespace std;

string helperFunc(string x, int n, int k);

int main()
{
	int t;
	cin >> t;
	cout << helperFunc("1", 1, t);
	return 0;
}

string helperFunc(string x, int n, int k)
{
	if (n == k)
	{
		return x;
	}
	string str = "";
	int count = 0;
	int left = 0;
	int right = 0;
	while (right < x.size())
	{
		while (right < x.size() && (x[left] == x[right]))
		{
			right++;
			count++;
		}
		left=right;
		string cnt = to_string(count);
		str += cnt;
		str += x[left-1];
		count=0;
	}
	return helperFunc(str, n+=1, k);
}