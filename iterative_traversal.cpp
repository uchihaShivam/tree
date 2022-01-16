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
   stack<Node *> s;
   Node *curr=root;
   while(s.empty()==false || curr!=NULL)
   {
       while(curr!=NULL)
       {
           s.push(curr);
           curr=curr->left;
       }
       curr=s.top();
       cout<<curr->key;
       s.pop();
       curr=curr->right;
   }
}

void pre_order_naive(Node *root)
{
     stack<Node *>s;
     s.push(root);
     while(!s.empty()){
         Node *curr=s.top();
         cout<<curr->key;
         s.pop();
         if(curr->right!=NULL)
         s.push(curr->right);
         if(curr->left!=NULL)
         s.push(curr->left);
     }
}
void preorder_traversal(Node *root)
{
    if(root==NULL)
    return;
    cout<<endl;
    stack<Node *> s;
    Node *curr=root;
    while (curr!=NULL || !s.empty())
    {
        while(curr!=NULL)
        {
            cout<<curr->key<<" ";
            if(curr->right!=NULL)
            s.push(curr->right);
            curr=curr->left;
        }
        if(!s.empty())
        {
            curr=s.top();
            s.pop();
        }
    }
    
}
int main()
{ 
   Node *root=new Node(10);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(40);
   inorder_traversal(root);
   cout<<"F";
//    iterative_travesal(root);
   cout<<endl;
   pre_order_naive(root);
   preorder_traversal(root);
}