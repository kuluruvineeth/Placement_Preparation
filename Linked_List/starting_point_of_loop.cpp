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
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void detectandremoveloop(no *head)
{

  if (head == NULL && head->next == NULL)
  {
    return;
  }

  no *fast = head;
  no *slow = head;

  slow = slow->next;
  fast = fast->next->next;

  while (fast && fast->next)
  {
    if (slow == fast) //loop exists
    {
      break;
    }
    slow = slow->next;
    fast = fast->next->next;
  }

  if (slow == fast)
  {
    slow = head;
    while (slow->next != fast->next) //we compare slow->next and fast->next until they match
    {
      slow = slow->next;
      fast = fast->next;
    }
    cout << fast->next->data << endl;
    fast->next = NULL; //removing loop and pointin gits next to null
  }
}

int main()
{
  no *head = new node(10);
  head->next = new node(20);
  head->next->next = new node(30);
  head->next->next->next = new node(40);
  head->next->next->next->next = new node(50);

  head->next->next->next->next->next = head->next->next;

  detectandremoveloop(head);
  cout << "linked list after removing loop" << endl;
  printlinkedlist(head);
  return 0;
}
