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