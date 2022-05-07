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

void print(no* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//to reverse linked list
no* reverse(no *head)
{
    no *curr = head;
    no *prev = NULL;
    no *next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}

no* addOne(no* head)
{
    //to get unit pos at head
    head = reverse(head);

    no* prev=NULL;
    no* curr=head;

    //as we want to add 1, hence initialize carry with 1
    int carry = 1;

    while(curr)
    {
        int newData = curr->data +carry;

        //if carry+curr->data is <10 means we are done as carry will be o and we wont change any value further
        if(newData<10)
        {
            curr->data = newData;
            carry=0;
            break;
        }
        //continue the loop and put unit pos in curr->data and pass rest to the carry
        else
        {
            curr->data = newData%10;
            carry = newData/10;
        }
        prev=curr;
        curr=curr->next;
    }
    //if still carry is left, make new node and add at the end of the LL
    if(carry>0)
    {
        while(carry)
        {
            no *newNode = new node(carry%10);
            prev->next = newNode;
            prev=newNode;
            carry/=10;
        }
    }
    //again reverse the LL to get back original one with+1
    head = reverse(head);
    return head;
}

int main()
{
    no* start = new node(4);
    start->next = new node(5);
    start->next->next = new node(6);
    print(start);
    addOne(start);
    print(start);
    return 0;
}