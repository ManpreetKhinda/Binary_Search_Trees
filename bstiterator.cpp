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
#include<stack>
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
class BSTIterator{
    private:stack<Node*> mystack;
    private:
    void pushall(Node*node){
        for(; node!=NULL;mystack.push(node),node=node->left);
    }
    public:
    BSTIterator(Node*root){
        pushall(root);
    }
    bool hasnext(){
        return !mystack.empty();
    }
    int next(){
        Node*tempnode=mystack.top();
        mystack.pop();
        pushall(tempnode->right);
        return tempnode->data;
    }
};