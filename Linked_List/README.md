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

## 4. [Remove loop](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/remove_loop.cpp)
```cpp
#include<bits/stdc++.h>
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
}no;

void print(no *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//Function to detect and remove loop
void detectAndRemoveLoop(no *head)
{
    //if list is empty or has only one node without loop
    if(head==NULL || head->next==NULL) return;

    no *slow=head, *fast=head;

    //move slow and fast 1 and 2 steps
    slow=slow->next;
    fast=fast->next->next;
    //search for loop using slow and fast pointers
    while(fast && fast->next)
    {
        if(slow==fast) break;
        slow=slow->next;
        fast=fast->next->next;
    }
    //if loop exists
    if(slow==fast)
    {
        slow = head;
        
        //this check is need when slow and fast both meet at the head of LL
        if(slow==fast)
        {
            while(fast->next != slow) fast=fast->next;
        }
        else
        {
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL; //remove loop
    }
}

int main()
{
    no *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = head;
    //print(head);
    detectAndRemoveLoop(head);
    print(head);
    return 0;
}
```

## 5. [Starting point of loop](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/first_node_in_loop.cpp)
```cpp
#include<bits/stdc++.h>
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
}no;

no *detectAndRemoveLoop(no *head)
{
    if(head==NULL || head->next==NULL) return NULL;

    no *slow=head, *fast=head;
    slow = head->next;
    fast = head->next->next;

    while(fast && fast->next)
    {
        if(slow==fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow!=fast) return NULL;

    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
    no *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = head->next;

    no *startPoint = detectAndRemoveLoop(head);
    cout<<"Starting point of loop is : "<<startPoint->data<<endl;
    return 0;
}
```

## 6. [Remove duplicates from sorted linked list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/remove_duplicates_from_sorted_linked_list.cpp)
```cpp
#include<bits/stdc++.h>
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
}no;

void print(no *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

no *removeDuplicates(no *head)
{
    //using pointer to iterare over linked list
    no *current = head;

    //traversing through the linked list
    while(current->next!=NULL)
    {
        //if data at current node and next node are same,we store the node
        //next to the next node of current node in link of cuurent node
        if(current->data == current->next->data)
        {
            current->next = current->next->next;
        }
        //else we just move pointer to next node
        else
        {
            current = current->next;
        }
    }
    return head;
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
  
  print(head);
  no *newHead = removeDuplicates(head);
  print(newHead);
  
  return 0;
}
```

## 7. [Remove duplicates from unsorted linked list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/remove_duplicates_from_unsorted_linked_list.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

/*
using hashing
TC: O(N)
SC: O(N)
*/
typedef struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data = d;
        next=NULL;
    }
}no;

void removeDuplicates(no* head)
{
    unordered_set<int> s;
    no *curr = head;
    
    //prev is address of last unique ele's pos.
    no* prev = NULL;
    while(curr)
    {
        //If current value is seen before
        if(s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            delete(curr);
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr=prev->next;
    }
}

void print(no* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    no* start = new node(10);
    start->next = new node(12);
    start->next->next = new node(11);
    start->next->next->next = new node(11);
    start->next->next->next->next = new node(12);
    start->next->next->next->next->next = new node(11);
    start->next->next->next->next->next->next = new node(10);
    print(start);
    removeDuplicates(start);
    print(start);
}
```