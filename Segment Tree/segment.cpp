#include <iostream>

using namespace std;
int N = 2e5+1;
int a[N],tree[4*N]; 

void buildTree(int node, int st,int end){
    if(st==end){
        tree[node] = a[st];
        return;
    }
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = tree[2*node] + tree[2*node +1];
}

int main()
{
    build(1,0,n-1)
    return 0;
}