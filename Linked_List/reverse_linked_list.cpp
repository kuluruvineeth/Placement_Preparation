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

/*
    recursive
    after running this function we just do
    ll.head = ll.reverse(ll.head);
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
no* reverse1(no* head)
{
  if(head==NULL || head->next==NULL) return head;

  /*reverse the rest list and put the first element at the end */
  no* rest = reverse1(head->next);
  head->next->next = head;

  head->next = NULL;

  //fix the head pointer
  return rest;
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
  
  //iterative
  printlinkedlist(head);
  reverse();
  printlinkedlist(head);
  
  /*recursive
  head = reverse1(head);
  printlinkedlist(head);
  */
  return 0;
}
