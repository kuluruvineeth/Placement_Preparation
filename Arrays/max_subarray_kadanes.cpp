#include <bits/stdc++.h>
using namespace std;

/*There are three approaches to solve this problem,but here i use only two methods
1.BETTER APPROACH : two loops method
2.OPTIMAL APPROACH : kadane's algorithm

*/

//1.BETTER APPROACH : TIME=O(N^2),SPACE=O(1)

void max_subarray_sum_better(vector<int> &v, int n)
{
  int max = 0;
  int maxi = 0;
  int maxj = -1;
  int sum;
  for (int i = 0; i < n; i++)
  {
    sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += v[j];
      if (sum > max)
      {
        max = sum;
        maxi = i;
        maxj = j;
      }
    }
  }
  for (int i = maxi; i <= maxj; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  cout << "maximum subarray sum is : " << max << endl;
}

//2.OPTIMAL APPROACH: TIME=O(N),SPACE=O(1)
void max_subarray_sum_optimal(vector<int> &v, int n)
{
  int sum = 0, maxsum = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    sum += v[i];
    maxsum = max(sum, maxsum);
    if (sum < 0)
    {
      sum = 0;
    }
  }
  cout << "maximum subarray sum is : " << maxsum << endl;
}

int main()
{
  vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
  int n = v.size();
  //max_subarray_sum_better(v, n);
  max_subarray_sum_optimal(v, n);
  return 0;
}
