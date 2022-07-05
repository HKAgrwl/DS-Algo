#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

BinaryTreeNode<int>* createBST(BinaryTreeNode<int>* root,int val){
    if(root==NULL){
        BinaryTreeNode<int>* rootNode = new BinaryTreeNode<int>*(val);
        return rootNode;
    }
    if(val>root->data){
        root->right = (root->right,val);
    }else{
        root->left = createBST(root->left,val);
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int n;
    cin>>n;
    BinaryTreeNode<int>* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        root = createBST(root,a);
    }
       
    return 0;
}
