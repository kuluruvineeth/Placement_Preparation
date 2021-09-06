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

void preorder_traversal(no *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

int identicaltrees(no *root1, no *root2)
{
  if (root1 == NULL && root2 == NULL)
  {
    return 1;
  }

  if (root1 != NULL && root2 != NULL)
  {
    return (root1->data == root2->data && identicaltrees(root1->left, root2->left) && identicaltrees(root1->right, root2->right));
  }
  return 0;
}

int main()
{
  no *root1 = new node(1);
  root1->left = new node(2);

  no *root2 = new node(1);
  root2->left = new node(3);

  if (identicaltrees(root1, root2))
  {
    cout << "Trees are identical!" << endl;
  }
  else
  {
    cout << "Trees are not identical" << endl;
  }
  return 0;
}
