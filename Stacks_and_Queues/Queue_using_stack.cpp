/* PROBLEM STATEMENT : Implementing Queue using stacks */

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
  stack<int> input, output;
  Queue()
  {
  }

  void push(int x)
  {
    input.push(x);
  }

  int pop()
  {
    if (output.empty())
    {
      while (input.size())
      {
        output.push(input.top());
        input.pop();
      }
    }
    int x = output.top();
    output.pop();
    return x;
  }

  int peek()
  {
    if (output.empty())
    {
      while (input.size())
      {
        output.push(input.top());
        input.pop();
      }
    }
    cout << output.top() << endl;
    return output.top();
  }

  bool empty()
  {
    return input.empty() and output.empty();
  }
};

int main()
{
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.pop();
  q.peek();
  return 0;
}