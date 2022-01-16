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
int max_ele(Node *root)
{
    if(root==NULL)
    return 0;
    int k=max(max_ele(root->left),root->key);
    k=max(max_ele(root->right),k);
    return k;
}
int getSize(Node* node)
{
   if(node==NULL)
   return 0;
   return getSize(node->left)+getSize(node->right)+1;
}
int main() {
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
	int k=max_ele(root);
    int f=getSize(root);
    cout<<k<<" "<<f;
}