/* PROBLEM STATEMENT : Given an array of numbers find lexicographically next permutation*/

#include <bits/stdc++.h>
using namespace std;

//1.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1)
void next_optimal(vector<int> &v, int n)
{
  int index = -1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (v[i] > v[i - 1])
    {
      index = i;
      break;
    }
  }
  if (index == -1)
  {
    reverse(v.begin(), v.end());
  }
  else
  {
    int previous = index;
    for (int i = index + 1; i < n; i++)
    {
      if (v[i] > v[index - 1] and v[i] <= v[previous])
      {
        previous = i;
      }
    }
    swap(v[index - 1], v[previous]);
    reverse(v.begin() + index, v.end());
  }
  for (int i = 0; i < n; i++)
  {
    cout << v[i];
  }
  cout << endl;
}

void nextPermutation(vector<int> &nums){
  int n = nums.size();
  int flag=0;
  for(int i=n-1;i>=0;i--){
    for(int j=i+1;j<=n;j++){
      if(nums[j]>nums[i]){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
        return;
      }
    }
    if(flag==0) sort(nums.begin()+i,nums.end());
  }
  return;
}

int main()
{
  //vector<int> v{1, 3, 5, 4, 2};
  vector<int> v1 = {1,2,3,6,5,4};

  //int n = v.size();
  //next_optimal(v, n);
  nextPermutation(v1);
  return 0;
}