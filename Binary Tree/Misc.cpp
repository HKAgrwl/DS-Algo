#include <iostream>
using namespace std;
// #include "BinaryTreeNode.h"
#include "BinaryTreeUse.cpp"

void mirror(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    BinaryTreeNode<int>* leftNode = root->left;
    root->left = root->right;
    root->right = leftNode;
    if(root->left){
        mirror(root->left);
    }
    if(root->right){
        mirror(root->right);
    }
}

bool findNode(BinaryTreeNode<int>* root ,int data){
    if(root==NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(findNode(root->left,data)){
        return true;
    }
    return findNode(root->right,data);
}

int numNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

void postOrderTraversal(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void preOrderTraversal(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int height(BinaryTreeNode<int>* root){
    if(root==NULL){ 
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1,max(option2,option3));
}

void Inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int search(int arr[],int start,int end, int value){
    int i;
    for(int i=start,i<end;i++){
        if(arr[i]==value){
            return i;
        }
    }
}

BinaryTreeNode<int>* buildTree(int inorder[], int preorder[], int inStart, int inEnd){
    static int preIndex=0;
     if(inStart> inEnd){
        return NULL:
     }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preIndex++]);

    if(inStart==inEnd){
        return root;
    }

    int inIndex = search(inorder,inStart,inEnd,root->data);

    root->left = buildTree(inorder,preorder,inStart,inIndex-1);
    root->right = buildTree(inorder,preorder,inIndex+1,inEnd);
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;
    
    int height = 1 + max(lh,rh);
    int diameter = 1 + max(lh+rh, max(ld,rd));

    pair<int,int> p;
    p.first = height;
    p.second = diameter;

    return p;
}
int main()
{   
    // int n;
    // cin>>n;
    BinaryTreeNode<int>* root = takeInputLevelwise();
    // printTree(root);
    // mirror(root);
    // printTree(root);
    // cout<<findNode(root,n);
    Inorder(root);
    return 0;
}
