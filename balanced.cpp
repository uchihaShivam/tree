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
    return max(height(root->left),height(root->right))+1;
}
bool naive(Node *root)
{
    if(root==NULL)
    return true;
    int left=height(root->left);
    int right=height(root->right);
    return (abs(left-right)<=1 && naive(root->left) && naive(root->right));
}
 int balanced(Node *root)
    {
        if(root==NULL)
        return 0;
        int l=balanced(root->left);
        if(l==-1)
        return -1;
        int r=balanced(root->right);
        if(r==-1)
        return -1;
        if(abs(l-r)>1)
        return -1;
        return max(l,r)+1;
    }
   
int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   root->left->left->left=new Node(40);
   bool k=naive(root);
   if(k)
   cout<<"balanced";
   else
   cout<<"not balanced";
   int f=balanced(root);
   if(f!=-1)
   cout<<"balanced";
   else 
   cout<<"not balanced";
}