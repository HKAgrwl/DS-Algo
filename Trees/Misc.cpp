#include <iostream>
using namespace std;
#include "TreeNode.h"
#include <queue>

void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

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

int maxSumNode(TreeNode<int>* root,int sum){
    static int maxSum=root->data;
    static int maxSumnode=0;
    sum+=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    if(sum > maxSum){
        maxSumnode=root->data;
        maxSum=sum;
    }
    for(int i=0;i<root->children.size();i++){
        maxSumNode(root->children[i],0);
    }
    return maxSumnode;
}

int countNodes(TreeNode<int>* root,int k){
    static int count=0;
    
    if(root==NULL){
        return -1;
    }
    if(root->data > k){
        count+=1;
    }
    for(int i=0;i<root->children.size();i++){
        countNodes(root->children[i],k);
    }
    return count;
}

int nextGreater(TreeNode<int>* root, int n){
    static int ans=0;
    static int temp=0;
    if(root==NULL){
        return -1;
    }
    if(root->data > n){
        temp = root->data;
    }
    if(ans==0){
        ans=temp;
    }
    if(temp<ans){
        ans=temp;
    }
    for(int i=0;i<root->children.size();i++){
        nextGreater(root->children[i],n);
    }
    return ans;
}

void replaceWithDepth(TreeNode<int>* root,int depth){
    if(root==NULL){
        return;
    }
    root->data = depth;

    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],depth+1);
    }
}

int main()
{
    // int n;
    // cin>>n;
    TreeNode<int>* root = takeInputLevelWise();
    int* max = &(root->data);
    int* sum  = new int(0);
    // maxNode(root,max);
    // cout<<*max;
    // sumNodes(root,sum);
    // cout<<height(root,1);
    // cout<<*sum;
    // postOrderTraversal(root);
    // cout<<maxSumNode(root,0);
    // cout<<countNodes(root,n);
    // cout<<nextGreater(root,n);
    replaceWithDepth(root,0);
    printTree(root);
    return 0;
}
