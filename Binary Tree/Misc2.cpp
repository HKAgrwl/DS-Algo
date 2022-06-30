#include <iostream>
using namespace std;
#include "BinaryTreeUse.cpp"
#include <queue>

void levelOrderTraversal(BinaryTreeNode<int>* root,int level){
    queue<pair<int,int> pendingNodes;
    pendingNodes.push(root);
    int level=0;
    while(!pendingNodes.empty()){
        
        cout<<p.first;
        
        pair<int,int> pLeft;
        p.first = root->left->data;
        p.second = level+1;
        pair<int,int> pRight;
        pRight.first = root->right->data;
        p.second = level+1;


    }   

}

int main()
{
    
    return 0;
}
