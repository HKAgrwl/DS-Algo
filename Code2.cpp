#include <iostream>
using namespace std;

int main()
{
    long t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int j = 0; j < n; j++)
        {
            long long  x;
            cin >> x;
            arr[j] = x;
        }
        long long  min = arr[0];
        for (long long k: arr)
        {
            if (k < min) {
                min = k;
            }
        }
        // cout<<min;
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {

            int dif = arr[j]-min;
            sum+=dif;
        }
        cout<<sum;
    }
    return 0;
}
