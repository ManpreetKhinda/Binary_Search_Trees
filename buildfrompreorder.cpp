#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorderf(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderf(root->left);
    preorderf(root->right);
    
}
Node*constructBST(int preorder[], int* preorderIDX, int key, int min, int max, int n){
    if(*preorderIDX>=n){
        return NULL;
    }
    Node*root=NULL;
    if(key>min && key<max){
        root=new Node(key);
        *preorderIDX+=1;
        if(*preorderIDX<n){
            root->left=constructBST(preorder,preorderIDX,preorder[*preorderIDX],min, key,n);
        }
        if(*preorderIDX<n){
            root->right=constructBST(preorder,preorderIDX,preorder[*preorderIDX],key, max,n);
        }
    }
    return root;
}
int main(){
    int preorder[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int preorderIDX=0;
    Node* root=constructBST(preorder,&preorderIDX,preorder[0],INT_MIN,INT_MAX,n);
    preorderf(root);
}