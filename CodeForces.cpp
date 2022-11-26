#include <iostream>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    for(int i=0;i<q;i++){
        int q_type;
        cin>>q_type;
        if(q_type==1) {
            int q_op1,q_op2;
            cin>>q_op1>>q_op2;
            arr[q_op1-1]=q_op2;
        }else{
           int q_op1,q_op2,q_op3;
           cin>>q_op1>>q_op2>>q_op3;
           
        }
    }
    return 0;
}
