/*
2 nodes of a bsst are swapped task is to restore the bst
inorder of bst is sorted
2 elements in a sorted array are swapped
3 pointer
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
void swap(int *a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void calcpointers(Node*root,Node**first,Node**mid,
                Node**last, Node**prev){
    if(root==NULL){
        return;
    }
    calcpointers(root->left,first,mid,last,prev);
    if(*prev &&root->data<(*prev)->data){
        if(!*first){
            *first=*prev;
            *mid=root;

        }
        else{
            *last=root;

        }
    }
    *prev=root;
    calcpointers(root->right,first,mid,last,prev);
}
void restore(Node*root){
    Node*first, *mid, *last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;
    calcpointers(root,&first,&mid,&last,&prev);
    if(first&&last){
        swap(&(first->data),&(last->data));
    }
    else if(first&&mid){
        swap(&(first->data),&(mid->data));
    }
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(4);
    root->right->right= new Node(13);
    inorder(root);
    cout<<endl;
    restore(root);
    inorder(root);
    cout<<endl;
}

