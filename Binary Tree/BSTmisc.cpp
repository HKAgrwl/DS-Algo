#include <iostream>
using namespace std;
#include "BSTUse.cpp"

class isBSTreturn{
    public:
    bool isBST;
    int minimum;
    int maximum;

};



int maximum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    int leftMax =   maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);

    return output;
}

// isBSTreturn isBSTimproved(BinaryTreeNode<int>* root){
//     if(root==NULL){
//         isBSTreturn output;
//         output.isBST =  true;
//         output.minimum = INT_MAX;
//         output.maximum=  INT_MIN;
//         return output;
//     }
//     isBSTreturn leftOutput = isBSTimproved(root->left);
//     isBSTreturn rightOutput = isBSTimproved(root->right);
//     int minimun = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
//     int maximun  = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
//     bool isBSTFinal = (root->data  > leftOutput.maximum ) && (root->data <= rightOutput.minimum) &&(leftOutput.isBST) && rightOutput.isBST;
//     isBSTreturn output; 
//     output.minimum = minimum;
//     output.maximum = maximum;
//     output.isBST = isBSTFinal;
//     return output;

// }

int findLCA(BinaryTreeNode<int>* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root->data;
    }
    int a = findLCA(root->left,n1,n2);
    int b = findLCA(root->right,n1,n2);
    if(a && b){
        return root->data;
    }
    if(b && !a){
        return b;
    }
    if(a && !b){
        return a;
    }
    return NULL;
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
    int lca = findLCA(root,4,6);
    cout<<lca;
    return 0;
}
