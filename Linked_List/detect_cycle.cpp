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

int detect_loop(no *head)
{
  no *slow = head;
  no *fast = head;
  while (slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  no *head = new node(10);
  head->next = new node(20);
  head->next->next = new node(30);
  head->next->next = head->next;
  if (detect_loop(head))
  {
    cout << "loop exists" << endl;
  }
  else
  {
    cout << "no loop exists" << endl;
  }
  return 0;
}
