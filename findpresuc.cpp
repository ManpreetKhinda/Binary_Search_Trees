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


void findPreSuc(Node*root,Node*&pre,Node*&suc,int key){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        if(root->left){
            Node*t=root->left;
            while(t->right){
                t=t->right;

            }
            pre=t;
        }
        if(root->right){
            Node*t=root->right;
            while(t->left){
                t=t->left;
            }
            suc=t;
        }

    }
    if(root->data>key){
        suc=root;
        findPreSuc(root->left,pre,suc,key);

    }
    if(root->data<key){
        pre=root;
        findPreSuc(root->right,pre,suc,key);

    }
}
