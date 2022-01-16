#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};
int is_child(Node *root)
{
    if(root==NULL || (root->right==NULL && root->left==NULL))
    return 1;
    int k=0;
    if(root->left!=NULL)
    k+=root->left->data;
    if(root->right!=NULL)
    k+=root->right->data;
    return (k==root->data && is_child(root->left) && is_child(root->right));
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(10);
    root->left->right = new Node(10);
    root->right->right = new Node(80);
    root->right->right->right = new Node(30);
    int ans = is_child(root);
    if (ans == 0)
        cout << "no";
    else
        cout << "yes";
}