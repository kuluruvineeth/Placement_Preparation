# List of Trie related questions for interview preparation

## 1. [Trie from scratch](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Trie/trie_from_scratch.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct Trienode
{
    char data;
    int wc;
    Trienode* child[26];
};
Trienode nodepool[100000]; //pool of 100k Trienodes
Trienode* root; //Root of Trie
int poolcount; //Always points to next free Trienode

//Initializer function
void init()
{
    poolcount = 0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for(int i=0;i<26;i++)
    {
        root->child[i] = NULL;
    }
}

Trienode* getNode(char c)
{
    Trienode* newnode = &nodepool[poolcount++];
    newnode->data = c;
    for(int i=0;i<26;i++)
    {
        newnode->child[i] = NULL;
    }
    newnode->wc = 0;
    return newnode;
}

void insert(char* s)
{
    Trienode* curr = root;
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index = s[i] - 'a';
        if(curr->child[index] == NULL)
        {
            curr->child[index] = getNode(s[i]);
        }
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }
}

bool search(char* s)
{
    Trienode* curr = root;
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index = s[i] - 'a';
        if(curr->child[index] == NULL || curr->child[index]->wc == 0)
        {
            return false;
        }
        curr = curr->child[index];
    }
    return true;
}

void Triedelete(char* s)
{
    if(search(s))
    {
        Trienode* curr = root;
        int index;
        for(int i=0;s[i]!='\0';i++)
        {
            index = s[i] - 'a';
            curr->child[index]->wc -= 1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(string s)
{
    Trienode* curr = root;
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index = s[i] - 'a';
        if(curr->child[index] == NULL || curr->child[index]->wc == 0)
        {
            return 0;
        }
        curr = curr->child[index];
    }
    return curr->wc;
}

int main()
{
    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};

    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    cout<<"No of strings with given prefix = "<<countPrefix("a")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("ar")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("arm")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("army")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("armi")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("ary")<<endl;

    cout<<"Deletion....STARTED\n";
    Triedelete(a);
    Triedelete(d);
    cout<<"DONE.....\n\n";

    cout<<"No of strings with given prefix = "<<countPrefix("a")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("ar")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("arm")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("army")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("armi")<<endl;
    cout<<"No of strings with given prefix = "<<countPrefix("ary")<<endl;

    return 0;
}
```

## 2. [Shortest unique prefix for every word](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Trie/shortest_unique_prefix_for_every_word.cpp)
```cpp
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
```

## 3. [Word break problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Trie/word_break_problem.cpp)
```cpp
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
```