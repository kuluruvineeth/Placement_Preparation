#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
}no;

void print(no* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void moveToFront(no* head)
{
    if(head==NULL || head->next==NULL) return;

    //to get address of last node
    no* last = head;

    //to get address of second last node
    no* second_last = NULL;

    //iterate till the end
    while(last->next!=NULL)
    {
        second_last=last;
        last=last->next;
    }
    //second last will point to NULL
    second_last->next = NULL;
    //last node will point to first node
    last->next=head;
    //change the head pointer to last node
    head=last;
}

int main()
{
    no* start = new node(10);
    start->next = new node(12);
    start->next->next = new node(11);
    print(start);
    moveToFront(start);
    print(start);
    return 0;
}