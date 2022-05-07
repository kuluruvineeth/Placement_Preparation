#include<bits/stdc++.h>
using namespace std;

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

void print(no *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

bool isCircular(no *head)
{
    if(head->next == NULL) return 0;

    no* curr = head->next;
    while(curr->next && curr->next!=head) curr=curr->next;
    return curr->next == head;
}

int main()
{
    no *head = new node(10);
    head->next = new node(20);
    head->next->next = head;
    cout<<isCircular(head)<<endl;
    return 0;
}