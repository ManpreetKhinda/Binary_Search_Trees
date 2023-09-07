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

void preorderf(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderf(root->left);
    preorderf(root->right);
}
/*2nCn/n+1*/
/*Application of catalan number
possible bst
paranthesis/bracket combination
possible forests
way of triangulations
possible paths in matrix
dividing a circle using N chords
dyck words of given length 
1,1,2,5,14,42,132,429,1430,4862

*/
int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
int mod=1e9+7;

int catalandp(int n, vector< long long int> &dp){
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=0;
            for(int j=1;j<=i;j++){
                dp[i]=(dp[i]+((dp[j-1]%mod)*(dp[i-j]%mod))%mod)%mod;
                
            }
        }
        return dp[n]%mod;
        
    }

/*
catalan using binomial coefficient*/
unsigned long long int  binomialcoeff(int n, int k){
    unsigned long int res=1;
    if(k>n-k){
        k=n-k;
    }
    for(int i=0;i<k;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
unsigned long int catalan(int n){
    unsigned long int c=binomialcoeff(2*n,n);
    return c/(n+1);
}
/*possible bst*/
vector<Node*> constructtrees(int start,int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<Node*> leftsubtree=constructtrees(start,i-1);
        vector<Node*> rightsubtree=constructtrees(i+1,end);

        for(int j=0;j<leftsubtree.size();j++){
            Node*left=leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++){
                Node*right=rightsubtree[k];
                Node*node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
int main(){
    vector<Node*> totalTrees=constructtrees(1,4);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<":";
        preorderf(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}