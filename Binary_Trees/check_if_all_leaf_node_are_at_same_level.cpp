#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
} no;

int checkLevelLeafNode(no *root)
{
    if (!root)
    {
        return 1;
    }
    // create a queue for level order traversal
    queue<no *> q;
    q.push(root);
    int result = INT_MAX;
    int level = 0;

    // traverse until the queue is empty
    while (!q.empty())
    {
        int size = q.size();
        level += 1;
        // traverse for complete level
        while (size > 0)
        {
            no *temp = q.front();
            q.pop();
            // check for left child
            if (temp->left)
            {
                q.push(temp->left);
                // if its leaf node
                if (!temp->left->left && !temp->left->right)
                {
                    // if its first leaf node, then update result
                    if (result == INT_MAX)
                    {
                        result = level;
                    }
                    // if its not first leaf node, then compare the level with level of previous leaf node
                    else if (result != level)
                    {
                        return 0;
                    }
                }
            }
            //check for right child
            if(temp->right)
            {
                q.push(temp->right);
                //if its leaf node
                if(!temp->right->left && !temp->right->right)
                {
                    if(result == INT_MAX)
                    {
                        result = level;
                    }
                    else if(result != level)
                    {
                        return 0;
                    }
                }
            }
            size--;
        }
    }
    return 1;
}

no *newNode(int data)
{
    no *root = new no;
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

int main()
{
    no *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(10);
    root->left->right = newNode(15);
    cout<<checkLevelLeafNode(root)<<endl;
    return 0;
}