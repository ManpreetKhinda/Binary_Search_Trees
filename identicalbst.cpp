/*
for given root nodes of 2 binary search trees print if the bsts
are identical or not identical bsts are structurally
identical and have equal values for the nodes in the structure
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
bool isidentical(Node*root1, Node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if( root1==NULL|| root2==NULL){
        return false;
    }
    else{
        bool cond1= root1->data==root2->data;
        bool cond2= isidentical(root1->left,root2->left);
        bool cond3=isidentical(root1->right,root2->right);


        if(cond1&&cond2&&cond3){
            return true;

        }
        return false;

    }
}

int main(){
    

}