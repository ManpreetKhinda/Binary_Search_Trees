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
Node*sortedtobst(int arr[],int start, int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node*root=new Node(arr[mid]);
    root->left=sortedtobst(arr,start,mid-1);
    root->right=sortedtobst(arr,mid+1,end);
    return root;
}

int main(){
    int arr[]={5,6,7,8,9,10,11};
    Node*root=sortedtobst(arr,0,6);
    preorderf(root);
    return 0;
}