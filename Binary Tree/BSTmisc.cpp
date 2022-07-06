#include <iostream>
using namespace std;
#include "BinaryTreeUse.cpp"

class isBSTreturn{
    public:
    bool isBST;
    int minimum;
    int maximum;

}



int maximum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)))
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left), minimum(root->right)))
}

bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    int leftMax =   maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right)

    return output;
}

isBSTreturn isBSTimproved(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTreturn output;
        output.isBST =  true;
        output.minimum = INT_MAX;
        output.maximum=  INT_MIN;
        return output;
    }
    isBSTreturn leftOutput = isBSTimproved(root->left);
    isBSTreturn rightOutput = isBSTimproved(root->right);
    int minimun = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximun  = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = (root->data  > leftOutput.maximum ) && (root->data <= rightOutput.minimum) &&(leftOutput.isBST) && rightOutput.isBST;
    isBSTreturn output; 
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    retrun output;

}


int main()
{
    
    return 0;
}
