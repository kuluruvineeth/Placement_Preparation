#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;

  node(int x) : data(x), left(NULL), right(NULL)
  {
  }
} no;

void preorder_traversal(no *node)
{
  if (node == NULL)
  {
    return;
  }
  cout << node->data << " ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

int checkheight(no *node)
{
  if (node == NULL)
  {
    return 0;
  }

  int leftheight = checkheight(node->left);
  if (leftheight == -1)
  {
    return -1;
  }

  int rightheight = checkheight(node->right);
  if (rightheight == -1)
  {
    return -1;
  }

  if (abs(leftheight - rightheight) > 1)
  {
    return -1;
  }

  else
  {
    return 1 + max(leftheight, rightheight);
  }
}

bool checkbalance(no *root)
{
  if (checkheight(root) == -1)
  {
    return false;
  }
  return true;
}

int main()
{
  no *root = new node(4);
  root->right = new node(5);
  root->left = new node(6);
  //root->right->right = new node(6);
  cout << checkbalance(root) << endl;
  preorder_traversal(root);
}
