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

no *detectAndRemoveLoop(no *head)
{
    if(head==NULL || head->next==NULL) return NULL;

    no *slow=head, *fast=head;
    slow = head->next;
    fast = head->next->next;

    while(fast && fast->next)
    {
        if(slow==fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow!=fast) return NULL;

    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
    no *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = head->next;

    no *startPoint = detectAndRemoveLoop(head);
    cout<<"Starting point of loop is : "<<startPoint->data<<endl;
    return 0;
}