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

void rotate_ll(no *head, int k)
{
  no *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = head;

  current = head;

  for (int i = 0; i < k - 1; i++)
  {
    current = current->next;
  }

  head = current->next;
  current->next = NULL;
  printlinkedlist(head);
}

int main()
{
  int n;
  cin >> n;
  int data;
  cin >> data;
  no *head = new node(data);
  no *tail = head;
  for (int i = 1; i < n; i++)
  {
    cin >> data;
    tail->next = new node(data);
    tail = tail->next;
  }
  printlinkedlist(head);
  int k;
  cin >> k;
  rotate_ll(head, k);

  return 0;
}
