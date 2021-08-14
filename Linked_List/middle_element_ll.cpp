#include <bits/stdc++.h>
using namespace std;

//i am just writing the optimum approach to get hold of middle element

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

void getmiddle(no *head)
{
  no *fast = head;
  no *slow = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  cout << "The middle element is  : " << slow->data << endl;
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
  getmiddle(head);
  return 0;
}
