/* PROBLEM STATEMENT : Find maxiumum value of worth you can take away even with partial takeaways*/

#include <bits/stdc++.h>
using namespace std;

struct item
{
  int value;
  int weight;
};

bool comp(item a, item b)
{
  double i1 = (double)a.value / (double)a.weight;
  double i2 = (double)b.value / (double)b.weight;
  return i1 > i2;
}

double fractional_knapsack(int W, item a[], int n)
{
  sort(a, a + n, comp);
  int current_weight = 0;
  double final_value = 0.0;
  for (int i = 0; i < n; i++)
  {
    if (current_weight + a[i].weight <= W)
    {
      current_weight += a[i].weight;
      final_value += a[i].value;
    }
    else
    {
      int remain = W - current_weight;
      final_value += (a[i].value / (double)a[i].weight) * (double)remain;
      break;
    }
  }
  return final_value;
}

int main()
{
  item a[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(a) / sizeof(a[0]);
  cout << fractional_knapsack(50, a, n) << endl;
  return 0;
}