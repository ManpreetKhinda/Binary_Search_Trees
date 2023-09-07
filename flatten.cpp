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
void inorder(vector<int>&traversal, Node* root){
if(root==NULL){
    return;
}
inorder(traversal, root->left);
traversal.push_back(root->data);
inorder(traversal, root->right);
}
void form(int pos, vector<int> traversal, Node*&prev){
    if(pos==traversal.size()){
        return;
    }
    prev->right=new Node(traversal[pos]);
    prev->left=NULL;
    prev=prev->right;
    form(pos+1,traversal, prev);
}
Node*flatten(Node*parent){
    Node* dummy=new Node(-1);
    Node* prev=dummy;
    vector<int> traversal;
    inorder(traversal, parent);
    form(0, traversal, prev);
    prev->left=NULL;
    prev->right=NULL;
    Node*ret=dummy->right;
    delete dummy;
    return ret;
}
/* making way out of inorder itself*/

void inorder1(Node*curr, Node*&prev){
    if(curr==NULL){
        return;
    }
    inorder1(curr->left, prev);
    prev->left=NULL;
    prev->right=curr;
    prev=curr;
    inorder1(curr->right, prev);
}
Node*flatten1(Node*parent){
    Node*dummy=new Node(-1);
    Node*prev=dummy;
    inorder1(parent,prev);
    prev->left=NULL;
    prev->right=NULL;
    Node*ret=dummy->right;
    delete dummy;
    return ret;
}
