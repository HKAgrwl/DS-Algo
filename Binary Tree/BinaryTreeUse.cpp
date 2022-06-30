#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <queue>

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

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data:"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left  = leftChild;
    root->right  = rightChild;
    return root;
}

BinaryTreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* rootNode = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Left of"<<rootNode->data<<endl;
        int leftNodeData,rightNodeData;
        cin>>leftNodeData;
        if(leftNodeData!=-1){
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftNodeData);
            pendingNodes.push(leftNode);
            rootNode->left = leftNode;
        }
        cout<<"Enter Right of"<<rootNode->data<<endl;
        cin>>rightNodeData;
        if(rightNodeData!=-1){
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightNodeData);
            pendingNodes.push(rightNode);
            rootNode->right = rightNode;
        }
    }
    return root;
}

// int main()
// {
//     // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
//     // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
//     // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
//     // root->left=node1;
//     // root->right=node2;
//     // BinaryTreeNode<int>* root = takeInput();
//     BinaryTreeNode<int>* root = takeInputLevelwise();
//     printTree(root);
//     delete(root);
//     return 0;
// }
