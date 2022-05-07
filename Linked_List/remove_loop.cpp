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

void print(no *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//Function to detect and remove loop
void detectAndRemoveLoop(no *head)
{
    //if list is empty or has only one node without loop
    if(head==NULL || head->next==NULL) return;

    no *slow=head, *fast=head;

    //move slow and fast 1 and 2 steps
    slow=slow->next;
    fast=fast->next->next;
    //search for loop using slow and fast pointers
    while(fast && fast->next)
    {
        if(slow==fast) break;
        slow=slow->next;
        fast=fast->next->next;
    }
    //if loop exists
    if(slow==fast)
    {
        slow = head;
        
        //this check is need when slow and fast both meet at the head of LL
        if(slow==fast)
        {
            while(fast->next != slow) fast=fast->next;
        }
        else
        {
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL; //remove loop
    }
}

int main()
{
    no *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = head;
    //print(head);
    detectAndRemoveLoop(head);
    print(head);
    return 0;
}