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
int mx=0,mx2=0;
int height(Node *root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}
void diameter(Node *root)
{
    if(root==NULL)
    return;
    int lh=height(root->left);
    int rh=height(root->right);
    // cout<<lh<<rh<<endl;
    if(lh+rh+1>mx)
    mx=lh+rh+1;
    diameter(root->left);
    diameter(root->right);    
}
int eff_diameter(Node *root)
{
    if(root==NULL)
    return 0;
    int d=eff_diameter(root->left);
    int e=eff_diameter(root->right);
    if((1+d+e)>mx2)
    mx2=1+d+e;
    return 1+max(d,e);
}
int main()
{
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   root->left->right=new Node(50);
   diameter(root);
   int f=eff_diameter(root);
   cout<<mx<<mx2;
}