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
int maxlevel=0;
void left_view(Node *root)
{
    if(root==NULL)
    return;
    queue<Node *> qu;
    qu.push(root);
    while(qu.empty()==false)
    {
        int k=qu.size();
        for(int i=0;i<k;i++)
        {
            Node *curr=qu.front();
            qu.pop();
            if(i==0)
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
            qu.push(curr->left);
            if(curr->right!=NULL)
            qu.push(curr->right);
        }
    }   
}
void left_view_2(Node *root,int level)
{
    if(root==NULL)
    return;
    if(maxlevel<level)
    {
        cout<<root->key<<" ";
        maxlevel=level;
    }
    left_view_2(root->left,level+1);
    left_view_2(root->right,level+1);
}
int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   left_view(root);
   left_view_2(root,1);
}