#include<bits/stdc++.h>
using namespace std;

class Solution
{
    struct TrieNode
    {
        TrieNode *child[26];
        bool isEnd;
        TrieNode()
        {
            for(int i=0;i<26;i++)
            {
                child[i] = NULL;
            }
            isEnd = false;
        }
    };

    void insertWord(TrieNode *root, string word)
    {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i]-'a';
            if(curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }

    void insertWords(TrieNode *root, vector<string> &words)
    {
        for(int i=0;i<words.size();i++)
        {
            insertWord(root,words[i]);
        }
    }

    bool searchWords(TrieNode *root, string word)
    {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++)
        {
            int index = word[i] - 'a';
            if(curr->child[index] == NULL)
            {
                return 0;
            }
            curr = curr->child[index];
        }
        return curr->isEnd;
    }

    bool func(TrieNode *root,string s)
    {
        int sz=s.size();
        if(sz==0)
        {
            return true;
        }
        for(int i=1;i<=sz;i++)
        {
            if(searchWords(root,s.substr(0,i)) && func(root,s.substr(i,sz-i)))
            {
                return true;
            }
        }
        return false;
    }

    public:
    int wordBreak(string A, vector<string> &B)
    {
        TrieNode *root = new TrieNode();
        insertWords(root,B);
        return func(root,A);
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
        vector<string> dict;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            dict.push_back(s);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line,dict)<<endl;
    }
}