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

int lenlist(no *head)
{
  int count = 0;
  while (head)
  {
    count++;
    head = head->next;
  }
  return count;
}

no *intersectionpoint(no *list1, no *list2)
{
  int len1 = lenlist(list1);
  int len2 = lenlist(list2);

  no *ptr1 = (len1 > len2) ? list1 : list2;
  no *ptr2 = (len1 > len2) ? list2 : list1;

  for (int i = 0; i < abs(len1 - len2); i++)
  {
    ptr1 = ptr1->next;
  }

  while (ptr1 && ptr2)
  {
    if (ptr1 == ptr2)
    {
      return ptr1;
    }
    else
    {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }
  return nullptr;
}

int main()
{
  no *list1 = new node(10);
  list1->next = new node(20);
  list1->next->next = new node(30);
  list1->next->next->next = new node(40);
  list1->next->next->next->next = new node(50);

  printlinkedlist(list1);

  no *list2 = new node(1);
  list2->next = new node(2);

  list2->next->next = list1->next->next;

  printlinkedlist(list2);

  no *intersectingpoint = intersectionpoint(list1, list2);

  if (intersectingpoint)
  {
    cout << "intersection data is : " << intersectingpoint->data << endl;
  }
  else
  {
    cout << "lists do not intersect " << endl;
  }
  return 0;
}
