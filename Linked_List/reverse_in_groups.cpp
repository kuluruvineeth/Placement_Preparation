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

no *reverse_in_groups(no *head, int k)
{
  if (head == NULL)
  {
    return NULL;
  }
  no *current = head;
  no *previous = NULL;
  no *nextp = NULL;
  int count = 0;
  while (current != NULL && count < k)
  {
    nextp = current->next;
    current->next = previous;
    previous = current;
    current = nextp;
    count++;
  }
  if (nextp != NULL)
  {
    head->next = reverse_in_groups(nextp, k);
  }
  return previous;
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
  no *rev = reverse_in_groups(head, k);
  printlinkedlist(rev);
  return 0;
}
