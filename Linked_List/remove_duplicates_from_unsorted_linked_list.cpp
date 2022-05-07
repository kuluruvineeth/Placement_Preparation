#include<bits/stdc++.h>
using namespace std;

/*
using hashing
TC: O(N)
SC: O(N)
*/
typedef struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data = d;
        next=NULL;
    }
}no;

void removeDuplicates(no* head)
{
    unordered_set<int> s;
    no *curr = head;
    
    //prev is address of last unique ele's pos.
    no* prev = NULL;
    while(curr)
    {
        //If current value is seen before
        if(s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            delete(curr);
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr=prev->next;
    }
}

void print(no* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    no* start = new node(10);
    start->next = new node(12);
    start->next->next = new node(11);
    start->next->next->next = new node(11);
    start->next->next->next->next = new node(12);
    start->next->next->next->next->next = new node(11);
    start->next->next->next->next->next->next = new node(10);
    print(start);
    removeDuplicates(start);
    print(start);
}