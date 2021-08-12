/* PROBLEM STATEMENT : Print pascal triangle */

/*There are three approaches to solve this problem.Approaches are in order of their efficieny
1.NAIVE APPROACH : 
2.BETTER APPROACH :
3.OPTIMAL APPROACH : 
*/

//3.OPTIMAL APPROACH: TIME=O(N^2),SPACE=O(N^2)
#include <bits/stdc++.h>
using namespace std;

void generate_pascal(int rows)
{
  vector<vector<int>> v(rows);
  for (int i = 0; i < rows; i++)
  {
    v[i].resize(i + 1);
    v[i][0] = v[i][i] = 1;

    for (int j = 0; j < i; j++)
    {
      v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  generate_pascal(9);
  return 0;
}