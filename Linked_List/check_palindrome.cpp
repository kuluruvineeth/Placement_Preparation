#include <bits/stdc++.h>
using namespace std;

/*Approach 1: Reverse the half the list and compare with other half.
 * Approach 2: Iterative Approach
 * 							- Push half the list in stack,
 * 							- Compare the rest of the list by popping off from the stack
 * Approach 3: Recursive Approach
*/

typedef struct node
{
  int data;
  struct node *next;

  node(char x)
  {
    data = x;
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

void reverselinkedlist(no *head)
{
  if (head == NULL || head->next == NULL)
  {
    return;
  }
  no *prev = NULL;
  no *next = NULL;
  while (head)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  head = prev;
}

bool ispalindrome1(no *head)
{
  if (head == NULL || head->next == NULL)
  {
    return true;
  }

  no *ptr1 = head;
  no *ptr2 = head;
  no *middlenode = NULL;

  while (ptr2 && ptr1 && ptr1->next)
  {
    ptr1 = ptr1->next->next;
    ptr2 = ptr2->next;
  }

  //in case of odd number of nodes ignore the middle node
  if (ptr1 && ptr1->next == NULL)
  {
    ptr2 = ptr2->next;
  }

  //reverse the second half of linkedlist
  reverselinkedlist(ptr2);

  middlenode = ptr2;

  ptr1 = head;

  //comparing two halves
  while (ptr1 && ptr2 && ptr1->data == ptr2->data)
  {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  //revresing the list again
  reverselinkedlist(middlenode);

  if (ptr2 == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//2.Iterative method using stack;

bool ispalindrome2(no *head)
{
  if (head == NULL && head->next == NULL)
  {
    return false;
  }

  no *ptr1 = head;
  no *ptr2 = head;

  //pushing the first half of list with nodes
  stack<no *> nodestack;

  while (ptr1 && ptr2 && ptr1->next)
  {
    ptr1 = ptr1->next->next;
    nodestack.push(ptr2);
    ptr2 = ptr2->next;
  }

  //in case of odd number of nodes ignore middle one
  if (ptr1 && ptr1->next == NULL)
  {
    ptr2 = ptr2->next;
  }

  while (!nodestack.empty() && ptr2)
  {
    no *current = nodestack.top();
    nodestack.pop();

    if (current->data != ptr2->data)
    {
      return false;
    }
    ptr2 = ptr2->next;
  }
  return true;
}

//3.Recursion method(bit tricky)

bool ispalindromesupporter(no *&left, no *right)
{
  //base case stop when right becomes null
  if (right == NULL)
  {
    return false;
  }

  //rest of the list should be palindrome
  bool isp = ispalindromesupporter(left, right->next);

  if (isp == false)
  {
    return false;
  }

  //checking values at current nodes
  isp = (left->data == right->data);

  //move left to next
  left = left->next;

  return isp;
}

bool ispalindromerecur(no *head)
{
  return ispalindromesupporter(head, head);
}

int main()
{
  int n;
  cin >> n;
  char data;
  cin >> data;
  no *head = new node(data);
  no *tail = head;

  for (int i = 1; i < n; i++)
  {
    cin >> data;
    tail->next = new node(data);
    tail = tail->next;
  }

  if (ispalindrome1(head))
  {
    cout << "it is palindrome" << endl;
  }
  else
  {
    cout << "not paindrome" << endl;
  }

  /*if(ispalindrome2(head))
	{
		cout<<"it is palindrome"<<endl;
	}
	else
	{
		cout<<"not paindrome"<<endl;
	}*/
  return 0;
}
