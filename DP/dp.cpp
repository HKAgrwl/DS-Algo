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

// Memoisation Approach
int fibo_2(int n){
    int* ans = new int[n+1];

    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}

// Recursive Approach
int reduceToOne(int x){
    static int count=0;
    if(x==1){
        return count;
    }
    count++;
    if(x%3==0){
        reduceToOne(x/3);
    }else if(x%2==0){
        reduceToOne(x/2);
    }else{
        reduceToOne(x-1);
    }
}

// Memoization Approach
int reduce_helper(int x,int* arr){
    static int count = 0;
    if(arr[x]!=-1){
        return count + arr[x];
    }
    count++;
    if(x%3==0){
        reduce_helper(x/3,arr);
    }
    else if(x%2==0){
        reduce_helper(x/2,arr);
    }else{
        reduce_helper(x-1,arr);
    }
}

int reduceToOne_2(int n){
    int* arr = new int[n+1];

    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    arr[1] = 0;
    arr[n] = reduce_helper(n,arr);
    return arr[n];
}

int main()
{
    int x;
    cin>>x;
    cout<<reduceToOne_2(x);
    return 0;
}
