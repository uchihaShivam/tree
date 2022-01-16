#include <bits/stdc++.h>
using namespace std; 
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};
int height(Node *root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right));
}
int burn(Node *root,int k)
{
    int h1=height(root);
    int h2=height(root->left);
    int h3=height(root->right);
    
}
int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   root->left->left->left=new Node(40);
   int k=burn(root,40);   
   cout<<k;
}