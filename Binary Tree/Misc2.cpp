#include <iostream>
using namespace std;
#include "BinaryTreeUse.cpp"
#include <queue>

vector<vector<int>> levelOrder(BinaryTreeNode<int>* root) {
        vector<vector<int>> ans;
        queue<BinaryTreeNode<int>*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        vector<int> interim;
        while(!pendingNodes.empty()){
            BinaryTreeNode<int>* current = pendingNodes.front();
            pendingNodes.pop();
            if(current==NULL && pendingNodes.empty()){
                break;
            }
            else if(current==NULL){
                ans.push_back(interim);
                interim.clear();
                pendingNodes.push(NULL);
            }else{
                interim.push_back(root->data);
                if(root->left) pendingNodes.push(root->left);
                if(root->right) pendingNodes.push(root->right);
            }
        }
        return ans;
    }

void levelOrderTraversal(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* current = pendingNodes.front();
        pendingNodes.pop();
        if(current==NULL && pendingNodes.empty()){
            break;
        }
        if(current == NULL){
            pendingNodes.push(NULL);
            cout<<endl;
        }else{
            cout<<current->data<<" ";
            if(current->left){
                pendingNodes.push(current->left);
            }
            if(current->right){
                pendingNodes.push(current->right);
            }
            
        }
    }   

}

void zigzag(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    int zz=1;
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* current = pendingNodes.front();
        pendingNodes.pop();
        if(current==NULL && pendingNodes.empty()){
            break;
        }
        if(current == NULL){
            pendingNodes.push(NULL);
            cout<<endl;
            zz*=-1;
        }else{
            cout<<current->data<<" ";
            if(zz==-1){
                if(current->left){
                    pendingNodes.push(current->left);
                }
                if(current->right){
                    pendingNodes.push(current->right);
                }
            }else{
                if(current->right){
                    pendingNodes.push(current->right);
                }
                if(current->left){
                    pendingNodes.push(current->left);
                }
            }
            
        }
    }   

}

BinaryTreeNode<int>* insertDup(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* leftNode = root->left;
    root->left = newNode;
    newNode->left = leftNode;
    insertDup(root->left->left);
    insertDup(root->right);
    return root;
}

BinaryTreeNode<int>* Lca(BinaryTreeNode<int>* root,int n1,int n2){
    if(root==NULL || root->data == n1 || root->data ==n2){
        return root;
    }
    if(Lca(root->left,n1,n1) && Lca(root->right,n1,n2)){
        return root;
    }
    if(Lca(root->left,n1,n2)==NULL){
        return Lca(root->right,n1,n2);
    }
    else{
        return Lca(root->left,n1,n2);
    }
}

void createBST(int n){
    
}

int main()
{
    // int a,b;
    // cin>>a>>b;
    BinaryTreeNode<int>* root = takeInputLevelwise();
    // insertDup(root);
    // levelOrderTraversal(root);
    // BinaryTreeNode<int>* lca = Lca(root,a,b);
    vector<vector<int>> x = levelOrder(root);
    // cout<<lca->data;
    // zigzag(root);
    return 0;
}
