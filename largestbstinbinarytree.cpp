/*
for each node store the following infromation
min in subtree
max in subtree
subtree size
size of largest bst
isbst
recursively traverse in a bottom up manner & find out the size of largest BST
*/


#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <climits>
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

struct info{
    int size;
    int maxval;
    int minval;
    int ans;
    bool isbst;
};
info largestbst(Node*root){
        if(root==NULL){
            return {0,INT_MIN,INT_MAX,0,true};
        }
        if(root->left==NULL && root->right==NULL){
            return {1,root->data,root->data,1,true};
        }
        info leftinfo=largestbst(root->left);
        info rightinfo=largestbst(root->right);
        info curr;
        curr.size=(1+leftinfo.size+rightinfo.size);
        if(leftinfo.isbst && rightinfo.isbst && leftinfo.maxval<root->data &&
        rightinfo.minval>root->data){
            curr.minval=min({leftinfo.minval,root->data});
            curr.maxval=max({rightinfo.maxval,root->data});
            curr.ans=leftinfo.ans+rightinfo.ans+1;
            curr.isbst=true;
            return curr;
        }
        curr.ans=max({leftinfo.ans,rightinfo.ans});
        curr.isbst=false;
        return curr;
    }
int main(){
    Node*root=new Node(15);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(5);
    // root->left->right=new Node(10);
    cout<<largestbst(root).ans<<endl;
}