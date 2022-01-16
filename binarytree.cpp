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
void inorder_traversal(Node *root)
{  
   if(root==NULL)
   return ;
   inorder_traversal(root->left);
   cout<<root->key<<endl;
   inorder_traversal(root->right);
}
void preorder_traversal(Node *root)
{  
   if(root==NULL)
   return ;
   cout<<root->key<<endl;
   inorder_traversal(root->left);
   inorder_traversal(root->right);
}
void postorder_traversal(Node *root)
{  
   if(root==NULL)
   return ;
   inorder_traversal(root->left);
   inorder_traversal(root->right);
   cout<<root->key<<endl;
}
void inline_traversal_line(Node *root)
{
   queue<Node* > qu;
   qu.push(root);
   qu.push(NULL);
   while(qu.size()> 1)
   {
      Node *curr=qu.front();
      qu.pop();
      if(curr==NULL)
      {
         cout<<endl;
         qu.push(NULL);
         continue;
      }
      cout<<curr->key<<" ";
      if(curr->left!=NULL)
      qu.push(curr->left);
      if(curr->right!=NULL)
      qu.push(curr->right);
   }
}
void inline_traversal(Node *root)
{
   queue<Node* > qu;
   qu.push(root);
   while(!qu.empty())
   {
      Node *curr=qu.front();
      qu.pop();
      cout<<curr->key<<" ";
      if(curr->left!=NULL)
      qu.push(curr->left);
      if(curr->right!=NULL)
      qu.push(curr->right);
   }
   cout<<endl;
}
void inline_traversal_line_2(Node *root)
{
   if(root==NULL)
   return;
   queue<Node *> qu;
   qu.push(root);
   while(!qu.empty())
   {
      int k=qu.size();
      for(int i=0;i<k;i++)
      {
      Node *curr=qu.front();
      qu.pop();
      cout<<curr->key<<" ";
      if(curr->left!=NULL)
      qu.push(curr->left);
      if(curr->right!=NULL)
      qu.push(curr->right);
      }
      cout<<endl;
   }
}
int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   inorder_traversal(root);
   preorder_traversal(root);
   postorder_traversal(root);
   inline_traversal(root);   
   inline_traversal_line(root);
   inline_traversal_line_2(root);
}