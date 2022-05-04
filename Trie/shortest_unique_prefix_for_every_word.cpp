#include<bits/stdc++.h>
using namespace std;

class Solution
{
    struct Node
    {
        Node *child[26];
        bool end;
        bool unique;
    };

    struct Node *getNode()
    {
        Node *temp = new Node;
        for(int i=0;i<26;i++)
        {
            temp->child[i] = NULL;
        }
        temp->end = false;
        temp->unique = true;
    }

    void insert(struct Node *root, string s)
    {
        Node *temp=root;
        for(int i=0;i<s.length();i++)
        {
            int index = s[i]-'a';
            if(!temp->child[index])
            {
                temp->child[index]=getNode();
            }
            else
            {
                temp->child[index]->unique=false;
            }
            temp=temp->child[index];
        }
        temp->end=true;
    }

    string prefix(Node *root, string s)
    {
        string st;
        for(int i=0;i<s.length();i++)
        {
            int index=s[i]-'a';
            st+=s[i];
            if(root->child[index]->unique)
            {
                return st;
            }
            root = root->child[index];
        }
    }

    public:
    vector<string> findPrefixes(string arr[],int n)
    {
        vector<string> ans;
        Node *root=getNode();
        for(int i=0;i<n;i++)
        {
            insert(root,arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(prefix(root,arr[i]));
        }
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr,n);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}