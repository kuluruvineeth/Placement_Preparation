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

no *return_kthnodefromlast_iterative(no *head, int k)
{
  no *ptr1, *ptr2;
  ptr1 = head;
  ptr2 = head;
  int i = 0;
  while (i < k && ptr1 != NULL)
  {
    ptr1 = ptr1->next;
    i++;
  }

  while (ptr1 != NULL)
  {
    ptr1 = ptr1->next; //by the time ptr1 reaches the end,the ptr2 would be at kth node
    ptr2 = ptr2->next;
  }

  return ptr2;
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
  no *temp = return_kthnodefromlast_iterative(head, 5);
  cout << temp->data << endl;
  return 0;
}
