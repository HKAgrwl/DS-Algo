#include <iostream>
using namespace std;
#include "TreeNode.h"
#include <queue>


TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no. of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter"<<i<<"th child of"<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }       
    } 
    return root;
}

void maxNode(TreeNode<int>* root,int* max){
    if(root==NULL){
        return;
    }
    if (root->data > *max){
        *max=root->data;
    }
    for(int i=0;i<root->children.size();i++){
        maxNode(root->children[i],max);
    }
} 
int height(TreeNode<int>* root,int h){
    if(root==NULL){
        return 0;
    }
    static int maxHeight = 1;

    if (h > maxHeight){
        maxHeight = h;
    }
    for(int i=0;i<root->children.size();i++){
        height(root->children[i],h+1);
    }
    return maxHeight;
} 

void postOrderTraversal(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    if(root->children.size()==0){ 
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrderTraversal(root->children[i]);
    } 
    cout<<root->data<<" ";
}


int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    int* max = &(root->data);
    int* sum  = new int(0);
    // maxNode(root,max);
    // cout<<*max;
    // sumNodes(root,sum);
    // cout<<height(root,1);
    // cout<<*sum;
    postOrderTraversal(root);
    return 0;
}
