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