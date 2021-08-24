/* PROBLEM STATEMENT : Implementing queue using array */

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

class Queue
{
  int front, rear;
  int a[MAX];

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }

  //to check whether queue is empty or not
  bool IsEmpty()
  {
    return (front == -1 and rear == -1);
  }

  //to check whether queue is full or not
  bool IsFull()
  {
    return (rear + 1) % MAX == front ? true : false;
  }

  //insers an element in queue at rear end
  void Enqueue(int x)
  {
    cout << "Enqueuing " << x << endl;
    if (IsFull())
    {
      cout << "Error: Queue is Full\n";
      return;
    }
    if (IsEmpty())
    {
      front = rear = 0;
    }
    else
    {
      rear = (rear + 1) % MAX;
    }
    a[rear] = x;
  }

  //removes an element in queue from front end
  void Dequeue()
  {
    cout << "Dequeuing \n";
    if (IsEmpty())
    {
      cout << "Error: Queue is Empty\n";
      return;
    }
    else if (front == rear)
    {
      rear = front = -1;
    }
    else
    {
      front = (front + 1) % MAX;
    }
  }

  //returns element at front of queue
  int Front()
  {
    if (front == -1)
    {
      cout << "Error: cannot return front from empty queue\n";
      return -1;
    }
    return a[front];
  }

  void print()
  {
    int count = (rear + MAX - front) % MAX + 1;
    cout << "Queue : ";
    for (int i = 0; i < count; i++)
    {
      int index = (front + i) % MAX;
      cout << a[index] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Queue q;
  q.Enqueue(2);
  q.print();
  q.Enqueue(4);
  q.print();
  q.Enqueue(6);
  q.print();
  q.Dequeue();
  q.print();
  q.Enqueue(8);
  q.print();
  return 0;
}