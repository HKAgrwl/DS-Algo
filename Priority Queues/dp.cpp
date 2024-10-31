/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int helper(vector<int> & nums,int start,double avg,int increase,int number)
{
    if(start==nums.size() )return 1;
    int ans=0;
    double sum=0;
    for(int i=start;i<nums.size();i++)
    {
        sum+=nums[i];
        int average=sum/(i-start+1);
        if(average>avg)
        {
            if(increase)ans+=helper(nums,i+1,average,!increase,number+1);
        }
        if(average<avg)
        {
            if(!increase)ans+=helper(nums,i+1,average,!increase,number+1);
        }
    }
    return ans;
}

int main()
{
    vector<int>nums={1,2,3,4,3,2,1};
    cout<<helper(nums,0,0,1,1);

    return 0;
}