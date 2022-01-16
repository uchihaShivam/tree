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
Node *bttodll(Node *root)
{
   if(root==NULL)
   return root;
   static Node *prev=NULL;
   Node *head=bttodll(root->left);
   if(prev==NULL)
   head=root;
   else
   {
       root->left=prev;
       prev->right=root;
   }
   prev=root;
   bttodll(root->right);
   return head;
}

int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   Node *head=bttodll(root);
   for(Node *curr=head;curr!=NULL;curr=curr->right)
    cout<<curr->key<<" ";
}