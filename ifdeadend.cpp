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
#include <stack>
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
/* for nodeval x x-1, x-2 should already exist*/
void fillmap(Node*root, map<int,int> &mp){
    if(root==NULL){
        return;
    }
    mp[root->data]=1;
    fillmap(root->left, mp);
    fillmap(root->right,mp);
}

bool check(Node*root, map<int,int> &mp){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL &&  root->right ==NULL){
        int pre=root->data-1;
        int suc=root->data+1;
        if(mp.find(pre)!=mp.end() && mp.find(suc)!=mp.end()){
            return true;
        }
    }
    return check(root->left,mp)|| check(root->right,mp);
}
bool isdeadend(Node*root, int min=1, int max=INT_MAX){
    if(!root){
        return false;
    }
    if(min==max){
        return true;
    }
    return isdeadend(root->left,min,root->data-1)
    ||isdeadend(root->right,root->data+1,max);
}