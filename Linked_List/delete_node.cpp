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

void delete_node_without_head(no *head)
{
  head->data = head->next->data;
  head->next = head->next->next;
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
  delete_node_without_head(head->next->next);
  printlinkedlist(head);
  return 0;
}
