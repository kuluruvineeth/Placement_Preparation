/* PROBLEM STATEMENT : Implement stack using queue */

#include <bits/stdc++.h>
using namespace std;

//1.Using two queues
class Stack
{
  queue<int> q1, q2;
  int cur_size;

public:
  Stack()
  {
    cur_size = 0;
  }

  void push(int x)
  {
    cur_size++;
    //push x first in empty q2
    q2.push(x);

    //push all remaining elements in q1 to q2
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
  }

  void pop()
  {
    if (q1.empty())
    {
      return;
    }
    q1.pop();
    cur_size--;
  }

  int top()
  {
    if (q1.empty())
    {
      return -1;
    }
    return q1.front();
  }

  int size()
  {
    return cur_size;
  }
};

/*int main()
{
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);

  cout << "current size: " << s.size() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << "current size: " << s.size() << endl;
  return 0;
}*/

//2.Using one queue
class Stack1
{
  queue<int> q;

public:
  void push(int x);
  void pop();
  int top();
  bool empty();
};

void Stack1::push(int x)
{
  //getting previous size of queue
  int s = q.size();

  q.push(x);

  //pop all previous elements and put them after current element
  for (int i = 0; i < s; i++)
  {
    q.push(q.front());
    q.pop();
  }
}

void Stack1::pop()
{
  if (q.empty())
  {
    cout << "No elements\n";
  }
  else
  {
    q.pop();
  }
}

int Stack1::top()
{
  return (q.empty()) ? -1 : q.front();
}

bool Stack1::empty()
{
  return (q.empty());
}

int main()
{
  Stack1 s;
  s.push(10);
  s.push(20);
  cout << s.top() << endl;
  s.pop();
  s.push(30);
  s.pop();
  cout << s.top() << endl;
  return 0;
}
