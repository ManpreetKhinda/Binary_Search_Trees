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

/*
bst for fast lookup insertion and deletion
rul1:- the left subtree contains only nodes with keys lesser than nodes key
rule2:-the right subtree contains only nodes with keys greater than node's key
rule3 the left and right should also be a binary tree there must be no duplicate nodes.

*/
// built bst from array
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

Node *insertbst(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertbst(root->left, val);
    }
    else
    {
        root->right = insertbst(root->right, val);
    }
    return root;
}
// search and deletion
Node *searchinbst(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchinbst(root->left, key);
    }
    return searchinbst(root->right, key);
}
// delete in bst
/*in case of inorder successor
replace with inorder successor
*/
Node *inordersuc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node* inordersuccesor(Node*root, Node*p){
    Node*succ=NULL;
    while(root!=NULL){
        if(p->data>=root->data)root=root->right;
        else{
            succ=root;
            root=root->left;
        }
}return succ;
}
Node *deleteinbst(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteinbst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = inordersuc(root->right);
        root->data = temp->data;
        root->right = deleteinbst(root->right, temp->data);
    }
    return root;
}

void inorder1(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder1(root->left);
    cout << root->data << " ";
    inorder1(root->right);
}
void inorder(Node *root,vector<int> t)
{
    
    if (root == NULL)
    {
        
    }
    inorder(root->left,t);
    t.push_back(root->data);
    inorder(root->right,t);

}
void preorderf(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderf(root->left);
    preorderf(root->right);8
}
int ceil(Node*root, int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        if(key>root->data)root=root->right;
        else {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
int floor(Node*root, int key){
    int floor=-1;
    while(root){
        if(root->data==key){
            floor=root->data;
            return floor;
        }
        if(key>root->data){
            floor=root->data;
            root=root->right;
        }
        else root=root->left;
    }
    return floor;
}
int main()
{
    Node *root = new Node(2);
    // root->left = new Node(2);
    root->right = new Node(4);
    // root->left->left = new Node(1);
    root->right->left= new Node(3);
    // root->left->right = new Node(3);
    // root->right->right = new Node(6);
    // root->left->left->right = new Node(7);
    // root->left->left->right->left = new Node(8);
    // root->left->left->right->right = new Node(9);

    // inorder(root);
    // cout<<endl;
    // root=deleteinbst(root,2);
    // vector<int> t ;
    // inorder(root,t);
    // for (auto i : t)
    // {
    //     cout << i;
    // }
    preorderf(root);

    return 0;
}