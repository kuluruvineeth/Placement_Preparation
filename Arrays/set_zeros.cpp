/*PROBLEM STATEMENT : Given a matrix of 0s and 1s make all columns and rows of 0th value as 0s*/

/*There are three approaches to solve this problem.Approaches are arranged in increasing order of their efficiency
1.NAIVE APPROACH : Using nested loops and extra temporary array space
2.BETTER APPROACH : Using extra rows and columns hash table
3.OPTIMAL APPROACH : Using first row and column as hash table
*/

#include <bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH : TIME=O(N*M*(N+M)),SPACE=O(N*M)
void set_zeros_naive(vector<vector<int>> &v, int m, int n)
{
  vector<vector<int>> temp(m, vector<int>(n, 0));

  //initializing temp array
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      temp[i][j] = 1;
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (v[i][j] == 0)
      {
        for (int k = 0; k < m; k++)
        {
          temp[k][j] = 0;
        }
        for (int k = 0; k < n; k++)
        {
          temp[i][k] = 0;
        }
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      v[i][j] = temp[i][j];
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

//2.BETTER APPROACH : TIME=O(N+M)+O(N*M)+O(N*M) = O(N*M),SPACE=O(M+N)
void set_zeros_better(vector<vector<int>> &v, int m, int n)
{
  vector<bool> r(m, false);
  vector<bool> c(n, false);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (v[i][j] == 0)
      {
        r[i] = true;
        c[j] = true;
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (r[i] == true or c[j] == true)
      {
        v[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

//3.OPTIMAL APPROACH: TIME=O(M) + O(N) + O(M*N) + O(M) + O(N)=O(M*N),SPACE=O(1)
void set_zeros_optimal(vector<vector<int>> &v, int m, int n)
{
  bool row1 = false, col1 = false;
  for (int j = 0; j < n; j++)
  {
    if (v[0][j] == 0)
    {
      row1 = true;
    }
  }
  for (int i = 0; i < m; i++)
  {
    if (v[i][0] == 0)
    {
      col1 = true;
    }
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (v[i][j] == 0)
      {
        v[i][0] = 0;
        v[0][j] = 0;
      }
    }
  }
  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (v[0][j] == 0 || v[i][0] == 0)
      {
        v[i][j] = 0;
      }
    }
  }
  if (row1 == true)
  {
    for (int j = 0; j < n; j++)
    {
      v[0][j] = 0;
    }
  }

  if (col1 == true)
  {
    for (int i = 0; i < m; i++)
    {
      v[i][0] = 0;
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> v{{1, 1, 1}, {1, 1, 1}, {0, 1, 1}};
  int m = v.size();
  int n = v[0].size();
  //set_zeros_naive(v, m, n);
  //set_zeros_better(v, m, n);
  set_zeros_optimal(v, m, n);
  return 0;
}