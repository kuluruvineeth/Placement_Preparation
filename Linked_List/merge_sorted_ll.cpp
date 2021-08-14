#include <bits/stdc++.h>
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
} no;

void printlinkedlist(no *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

no *merge_ll(no *list1, no *list2)
{
  no *head = new node(0);
  no *merged = head;

  no *head1 = list1;
  no *head2 = list2;

  while (head1 != NULL && head2 != NULL)
  {
    if (head1->data < head2->data)
    {
      merged->next = head1;
      head1 = head1->next;
    }
    else
    {
      merged->next = head2;
      head2 = head2->next;
    }
    merged = merged->next;
  }

  if (head1 != NULL)
  {
    merged->next = head1;
  }
  if (head2 != NULL)
  {
    merged->next = head2;
  }
  return head->next;
}

int main()
{
  no *head1 = new node(10);
  head1->next = new node(20);
  head1->next->next = new node(30);

  no *head2 = new node(1);
  head2->next = new node(2);
  head2->next->next = new node(3);

  no *merged = merge_ll(head1, head2);

  printlinkedlist(merged);
  return 0;
}
