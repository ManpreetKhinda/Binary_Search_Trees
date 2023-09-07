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
bool canRepresentBST(int pre[], int n){
    stack<int> s;
    int root=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre[i]<root){
            return false;
        }
        while(!s.empty() && s.top()<pre[i]){
            root=s.top();
            s.pop();
        }
        s.push(pre[i]);
    }

}