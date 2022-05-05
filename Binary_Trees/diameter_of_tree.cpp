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

int diameter(no *root)
{
    no* temp;
    queue<no*> q;
    q.push(root);
    int mx=INT_MIN,lh,rh;
    while(q.size())
    {
        temp = q.front();

        //find height of subtrees of root
        lh = height(temp->left);
        rh = height(temp->right);

        //pushing left subtree and right subtree address
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        // storing maximum of the prev and current diameter
        mx = max(mx,lh+rh+1);
        q.pop();
    }
    return mx;
}

int main()
{
  no *root = new node(1);
  root->left = new node(2);
  root->left->right = new node(3);
  root->left->right->left = new node(4);

  cout << "Diameter of tree is : " << diameter(root) << endl;
  return 0;
}
