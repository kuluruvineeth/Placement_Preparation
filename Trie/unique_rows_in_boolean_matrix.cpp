#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

struct trie
{
    struct trie* child[2]={NULL};
    bool isleaf=false;
};

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int>> ans;
    trie *root=new trie();
    for(int i=0;i<row;i++)
    {
        int w=0;
        trie *p=root;
        vector<int> v;
        for(int j=0;j<col;j++)
        {
            if(p->child[M[i][j]]==NULL)
            {
                p->child[M[i][j]]=new trie();
                w=1;
            }
            p=p->child[M[i][j]];
            v.push_back(M[i][j]);
        }
        if(w==1)
        {
            ans.push_back(v);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a[MAX][MAX];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<vector<int>> res = uniqueRow(a,m,n);
        for(int i=0;i<res.size();i++)
        {
            for(int x : res[i])
            {
                cout<<x<<" ";
            }
            cout<<"$";
        }
        cout<<endl;
    }
}