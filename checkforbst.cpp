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

bool isbst(Node*root, Node*min=NULL,Node*max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL &&root->data<=min->data){
        return false;
    }
    if(max!=NULL &&root->data>=max->data){
        return false;
    }
    bool leftvaild=isbst(root->left,min,root);
    bool rightvalid=isbst(root->right,root,max);
    return leftvaild && rightvalid;



}
int main(){
    Node*root1=new Node(1);
    root1->left= new Node(2);
    root1->right=new Node(3);
    cout<<isbst(root1,NULL,NULL);
}