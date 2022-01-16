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
int count_naive(Node *root)
{
    if(root==NULL)
    return 0;
    return 1+count_naive(root->left)+count_naive(root->right);
}
int count_eff(Node *root)
{
    if(root==NULL)
    return 0;
    Node *curr=root;
    int lh=0,rh=0;
    while (curr!=NULL)
    {
        curr=curr->left;
        lh++;
    }
    curr=root;
    while(curr!=NULL)
    {
        rh++;
        curr=curr->right;
    }
    if(lh==rh)
      return pow(2,lh)-1;
    return 1+count_eff(root->left)+count_eff(root->right);
}
int main()
{
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   root->left->right=new Node(50);
   int k=count_naive(root);
   cout<<k;
   int f=count_eff(root);
   cout<<" "<<f<<endl;
}