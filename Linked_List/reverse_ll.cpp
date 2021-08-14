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

no *head;

void printlinkedlist(no *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void reverse()
{
  no *current = head;
  no *previous = NULL;
  no *nextp = NULL;
  while (current != NULL)
  {
    nextp = current->next;
    current->next = previous;
    previous = current;
    current = nextp;
  }
  head = previous;
}

int main()
{
  int n;
  cin >> n;
  int data;
  cin >> data;
  head = new node(data);
  no *tail = head;
  for (int i = 1; i < n; i++)
  {
    cin >> data;
    tail->next = new node(data);
    tail = tail->next;
  }

  printlinkedlist(head);
  reverse();
  printlinkedlist(head);
  return 0;
}
