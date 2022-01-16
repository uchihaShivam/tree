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
bool findca(Node *root,vector<Node *> &a,int n)
{   
    if(root==NULL)
    return false;
    a.push_back(root);
    if(root->key==n)
    return true;
    if(findca(root->left,a,n)||findca(root->right,a,n))
    return true;
    a.pop_back();
    return false;
}
Node *lca_1(Node *root,int n1,int n2)
{
   vector<Node *> p,q;
   if(root==NULL)
   return NULL;
   if(findca(root,p,n1)==false || findca(root,q,n2)==false)
   return NULL;
   for(int i=0;i<p.size()&&i<q.size();i++)
   {
       if(p[i+1]!=q[i+1])
       return p[i];
   }
   return p[p.size()-1];
}
Node *lca_2(Node *root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->key==n1 || root->key==n2)
    return root;
    Node *lca1=lca_2(root->left,n1,n2);
    Node *lca2=lca_2(root->right,n1,n2);
    if(lca1!=NULL && lca2!=NULL)
    return root;
    if(lca1!=NULL)
    return lca1;
    else
    return lca2;
}
int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(50);
   root->left->left->left=new Node(40);
   Node *k=lca_1(root,30,50);
   cout<<k->key<<endl;
}