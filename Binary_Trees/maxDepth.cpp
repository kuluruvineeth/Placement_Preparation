#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;

  node(int value)
  {
    data = value;
    left = NULL;
    right = NULL;
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

int height(no *root)
{
  if (root == NULL)
  {
    return 0;
  }

  else
  {
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if (leftheight > rightheight)
    {
      return (leftheight + 1);
    }

    else
    {
      return (rightheight + 1);
    }
  }
}

int main()
{
  no *root = new node(1);
  root->left = new node(2);
  root->left->right = new node(3);

  cout << "height of tree is : " << height(root) << endl;
  return 0;
}
