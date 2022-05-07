#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data=d;
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

no* findIntersection(no *head1, no *head2)
{
    no *head = NULL;
    no *temp;
    no *prev = NULL;
    while(head1 && head2)
    {
        //take data from current head of both linked list
        int a = head1->data;
        int b = head2->data;

        //if both are equal, make new node move both pointers ahead
        if(a==b)
        {
            temp = new node(a);
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                prev->next=temp;
            }
            head2=head2->next;
            head1=head1->next;
            prev=temp;
        }
        // whoevers value is small should be forwarded
        else if(a>b) head2 = head2->next;
        else head1=head1->next;
    }
    return head;
}

int main()
{
  no *list1 = new node(10);
  list1->next = new node(20);
  list1->next->next = new node(30);
  list1->next->next->next = new node(40);
  list1->next->next->next->next = new node(50);

  no *list2 = new node(10);
  list2->next = new node(15);
  list2->next->next = new node(20);
  list2->next->next->next = new node(25);
  list2->next->next->next->next = new node(30);

  no *head = findIntersection(list1,list2);
  print(head);
  return 0;
}