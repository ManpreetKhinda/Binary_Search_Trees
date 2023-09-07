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
/*
strategy
use 2 stacks curren level and next level
variable left to right
if left to right push left child then right else push right child then left


*/
void zigzag(Node *root)
{   if(root==NULL){
    return;
}
    stack<Node *> currlevel;
    stack<Node *> nextlevel;
    bool leftotright = true;
    currlevel.push(root);
    while (!currlevel.empty())
    {
        Node *temp = currlevel.top();
        currlevel.pop();
        if (temp)
        {
            cout << temp->data << " ";

            if (leftotright)
            {
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }
        if(currlevel.empty()){
            leftotright=!leftotright;
            swap(currlevel,nextlevel);
        }
    }
}
int main(){
    Node*root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);

    zigzag(root);
    cout<<endl;

}