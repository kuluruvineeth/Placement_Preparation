# List of Linked List questions for Interview Preparation

## 1. [Reverse linked list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/reverse_linked_list.cpp)
```cpp
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
```

## 2. [Reverse in Groups](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/reverse_in_groups.cpp)
```cpp
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
```

## 3. [Detect Loop](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/detect_cycle.cpp)
```cpp
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
```