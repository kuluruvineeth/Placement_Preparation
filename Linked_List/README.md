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

## 8. [Move last element to front](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/move_last_ele_to_front.cpp)
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

void print(no* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void moveToFront(no* head)
{
    if(head==NULL || head->next==NULL) return;

    //to get address of last node
    no* last = head;

    //to get address of second last node
    no* second_last = NULL;

    //iterate till the end
    while(last->next!=NULL)
    {
        second_last=last;
        last=last->next;
    }
    //second last will point to NULL
    second_last->next = NULL;
    //last node will point to first node
    last->next=head;
    //change the head pointer to last node
    head=last;
}

int main()
{
    no* start = new node(10);
    start->next = new node(12);
    start->next->next = new node(11);
    print(start);
    moveToFront(start);
    print(start);
    return 0;
}
```

## 9. [Add one to linked list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/add_1_to_linked_list.cpp)
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
        next=NULL;
    }
}no;

void print(no* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//to reverse linked list
no* reverse(no *head)
{
    no *curr = head;
    no *prev = NULL;
    no *next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    return prev;
}

no* addOne(no* head)
{
    //to get unit pos at head
    head = reverse(head);

    no* prev=NULL;
    no* curr=head;

    //as we want to add 1, hence initialize carry with 1
    int carry = 1;

    while(curr)
    {
        int newData = curr->data +carry;

        //if carry+curr->data is <10 means we are done as carry will be o and we wont change any value further
        if(newData<10)
        {
            curr->data = newData;
            carry=0;
            break;
        }
        //continue the loop and put unit pos in curr->data and pass rest to the carry
        else
        {
            curr->data = newData%10;
            carry = newData/10;
        }
        prev=curr;
        curr=curr->next;
    }
    //if still carry is left, make new node and add at the end of the LL
    if(carry>0)
    {
        while(carry)
        {
            no *newNode = new node(carry%10);
            prev->next = newNode;
            prev=newNode;
            carry/=10;
        }
    }
    //again reverse the LL to get back original one with+1
    head = reverse(head);
    return head;
}

int main()
{
    no* start = new node(4);
    start->next = new node(5);
    start->next->next = new node(6);
    print(start);
    addOne(start);
    print(start);
    return 0;
}
```

## 10. [Add two lists](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/add_lists.cpp)
```cpp
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
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

no *add(no *list1, no *list2)
{
  if (list1 == NULL)
  {
    return list2;
  }
  if (list2 == NULL)
  {
    return list1;
  }

  //res will store result
  no *res = NULL;

  no *prev = NULL;

  int value = 0, carry = 0;

  while (list1 || list2)
  {
    value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
    if (value > 9)
    {
      carry = 1;
      value = value % 10;
    }

    else
    {
      carry = 0;
    }

    no *temp = new node(value);

    if (res == NULL)
    {
      res = temp;
    }

    else
    {
      prev->next = temp;
    }
    prev = temp;

    if (list1)
    {
      list1 = list1->next;
    }

    if (list2)
    {
      list2 = list2->next;
    }
  }
  if (carry > 0)
  {
    prev->next = new node(carry);
  }
  return res;
}

int main()
{
  int n1;
  cin >> n1;
  int d1;
  cin >> d1;
  no *head1 = new node(d1);
  no *tail1 = head1;
  for (int i = 1; i < n1; i++)
  {
    cin >> d1;
    tail1->next = new node(d1);
    tail1 = tail1->next;
  }

  int n2;
  cin >> n2;
  int d2;
  cin >> d2;
  no *head2 = new node(d2);
  no *tail2 = head2;

  for (int i = 1; i < n2; i++)
  {
    cin >> d2;
    tail2->next = new node(d2);
    tail2 = tail2->next;
  }
  no *r = add(head1, head2);
  printlinkedlist(r);
  return 0;
}
```

## 11. [Intersection point of two linked list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/intersection_point.cpp)
```cpp
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
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int lenlist(no *head)
{
  int count = 0;
  while (head)
  {
    count++;
    head = head->next;
  }
  return count;
}

no *intersectionpoint(no *list1, no *list2)
{
  int len1 = lenlist(list1);
  int len2 = lenlist(list2);

  no *ptr1 = (len1 > len2) ? list1 : list2;
  no *ptr2 = (len1 > len2) ? list2 : list1;

  for (int i = 0; i < abs(len1 - len2); i++)
  {
    ptr1 = ptr1->next;
  }

  while (ptr1 && ptr2)
  {
    if (ptr1 == ptr2)
    {
      return ptr1;
    }
    else
    {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }
  return nullptr;
}

int main()
{
  no *list1 = new node(10);
  list1->next = new node(20);
  list1->next->next = new node(30);
  list1->next->next->next = new node(40);
  list1->next->next->next->next = new node(50);

  printlinkedlist(list1);

  no *list2 = new node(1);
  list2->next = new node(2);

  list2->next->next = list1->next->next;

  printlinkedlist(list2);

  no *intersectingpoint = intersectionpoint(list1, list2);

  if (intersectingpoint)
  {
    cout << "intersection data is : " << intersectingpoint->data << endl;
  }
  else
  {
    cout << "lists do not intersect " << endl;
  }
  return 0;
}
```

## 12. [Intersection of two sorted linked list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Linked_List/intersection_of_two_linked_list.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data=d;
        next=NULL;
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

no* findIntersection(no *head1, no *head2)
{
    no *head = NULL;
    no *temp;
    no *prev = NULL;
    while(head1 && head2)
    {
        //take data from current head of both linked list
        int a = head1->data;
        int b = head2->data;

        //if both are equal, make new node move both pointers ahead
        if(a==b)
        {
            temp = new node(a);
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                prev->next=temp;
            }
            head2=head2->next;
            head1=head1->next;
            prev=temp;
        }
        // whoevers value is small should be forwarded
        else if(a>b) head2 = head2->next;
        else head1=head1->next;
    }
    return head;
}

int main()
{
  no *list1 = new node(10);
  list1->next = new node(20);
  list1->next->next = new node(30);
  list1->next->next->next = new node(40);
  list1->next->next->next->next = new node(50);

  no *list2 = new node(10);
  list2->next = new node(15);
  list2->next->next = new node(20);
  list2->next->next->next = new node(25);
  list2->next->next->next->next = new node(30);

  no *head = findIntersection(list1,list2);
  print(head);
  return 0;
}
```