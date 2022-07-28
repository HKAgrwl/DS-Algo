#include <iostream>
using namespace std;

int fibo_helper(int n,int* ans){
    if(n<=1){
        return n;
    }

    // check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }

    int a = fibo_helper(n-1,ans);
    int b = fibo_helper(n-2,ans);

    ans[n] = a+b;
    return ans[n];

}


int main()
{
    
    return 0;
}
