#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *next;

  node(int x)
  {
    data = x;
    next = NULL;
  }
} no;

void printlinkedlist(no *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

no *add(no *list1, no *list2)
{
  if (list1 == NULL)
  {
    return list2;
  }
  if (list2 == NULL)
  {
    return list1;
  }

  //res will store result
  no *res = NULL;

  no *prev = NULL;

  int value = 0, carry = 0;

  while (list1 || list2)
  {
    value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
    if (value > 9)
    {
      carry = 1;
      value = value % 10;
    }

    else
    {
      carry = 0;
    }

    no *temp = new node(value);

    if (res == NULL)
    {
      res = temp;
    }

    else
    {
      prev->next = temp;
    }
    prev = temp;

    if (list1)
    {
      list1 = list1->next;
    }

    if (list2)
    {
      list2 = list2->next;
    }
  }
  if (carry > 0)
  {
    prev->next = new node(carry);
  }
  return res;
}

int main()
{
  int n1;
  cin >> n1;
  int d1;
  cin >> d1;
  no *head1 = new node(d1);
  no *tail1 = head1;
  for (int i = 1; i < n1; i++)
  {
    cin >> d1;
    tail1->next = new node(d1);
    tail1 = tail1->next;
  }

  int n2;
  cin >> n2;
  int d2;
  cin >> d2;
  no *head2 = new node(d2);
  no *tail2 = head2;

  for (int i = 1; i < n2; i++)
  {
    cin >> d2;
    tail2->next = new node(d2);
    tail2 = tail2->next;
  }
  no *r = add(head1, head2);
  printlinkedlist(r);
  return 0;
}
