// /* PROBLEM STATEMENT : Given two sorted arrays merge them without using extra space*/

// /*There are three approaches to solve this problem.Approaches are in increasing order of their efficiency
// 1.NAIVE APPROACH : copy both elements in one single array and then sort and place back.
// 2.BETTER APPROACH : like insertion sorting
// 3.OPTIMAL APPROACH : GAP method(intuition of shell sort)
// */

// #include <bits/stdc++.h>
// using namespace std;

// //1.NAIVE APPROACH : TIME=O(NLOGN) + O(N) + O(N),SPACE=O(N)
// void merge_naive(vector<int> &v1, int n, vector<int> &v2, int m)
// {
//   vector<int> v;
//   for (int i = 0; i < n; i++)
//   {
//     v.push_back(v1[i]);
//   }
//   for (int i = 0; i < m; i++)
//   {
//     v.push_back(v2[i]);
//   }
//   for (int i = 0; i < n + m; i++)
//   {
//     cout << v[i] << " ";
//   }
//   cout << endl;
//   sort(v.begin(), v.end());

//   for (int i = 0; i < n; i++)
//   {
//     v1[i] = v[i];
//   }

//   for (int i = 0; i < m; i++)
//   {
//     v2[i] = v[n + i];
//   }

//   for (int i = 0; i < n; i++)
//   {
//     cout << v1[i] << " ";
//   }
//   cout << endl;
//   for (int i = 0; i < m; i++)
//   {
//     cout << v2[i] << " ";
//   }
//   cout << endl;
// }

// //2.BETTER APPROACH : TIME=O(N*M),SPACE=O(1)
// void merge_better(vector<int> &v1, int n, vector<int> &v2, int m)
// {
//   for (int i = 0; i < n; i++)
//   {
//     if (v1[i] > v2[0])
//     {
//       swap(v1[i], v2[0]);
//       int j = 0;
//       while ((j + 1) < m and v2[j] > v2[j + 1])
//       {
//         swap(v2[j], v2[j + 1]);
//         j++;
//       }
//     }
//   }
//   for (int i = 0; i < n; i++)
//   {
//     cout << v1[i] << " ";
//   }
//   cout << endl;
//   for (int i = 0; i < m; i++)
//   {
//     cout << v2[i] << " ";
//   }
//   cout << endl;
// }

// int nextgap(int gap)
// {
//   if (gap <= 1)
//   {
//     return 0;
//   }
//   return (gap / 2) + (gap % 2);
// }

// //3.OPTIMAL APPROACH: TIME=O(NLOGN),SPACE=O(1)
// void merge_optimal(vector<int> &v1, int n, vector<int> &v2, int m)
// {
//   int i, j, gap = n + m;
//   for (gap = nextgap(gap); gap > 0; gap = nextgap(gap))
//   {
//     //comparing elements in first array
//     for (int i = 0; i + gap < n; i++)
//     {
//       if (v1[i] > v1[i + gap])
//       {
//         swap(v1[i], v1[i + gap]);
//       }
//     }

//     //comparing elements in both arrays
//     for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
//     {
//       if (v1[i] > v2[j])
//       {
//         swap(v1[i], v2[j]);
//       }
//     }

//     if (j < m)
//     {
//       // comparing elements in the second array
//       for (j = 0; j + gap < m; j++)
//       {
//         if (v2[j] > v2[j + gap])
//         {
//           swap(v2[j], v2[j + gap]);
//         }
//       }
//     }
//   }

//   for (int i = 0; i < n; i++)
//   {
//     cout << v1[i] << " ";
//   }
//   cout << endl;
//   for (int i = 0; i < m; i++)
//   {
//     cout << v2[i] << " ";
//   }
//   cout << endl;
// }

// int main()
// {
//   vector<int> v1{1, 4, 7, 8, 10};
//   int n = v1.size();
//   vector<int> v2{2, 3, 9};
//   int m = v2.size();
//   //merge_naive(v1, n, v2, m);
//   //merge_better(v1, n, v2, m);
//   merge_optimal(v1, n, v2, m);
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int nextGap(int gap)
{
  if (gap <= 1)
    return 0;
  return (gap / 2) + (gap % 2);
}
void merge(int arr1[], int arr2[], int n, int m)
{
  int i, j, gap = n + m;
  for (gap = nextGap(gap);
       gap > 0; gap = nextGap(gap))
  {
    // comparing elements in the first array.
    for (i = 0; i + gap < n; i++)
      if (arr1[i] > arr1[i + gap])
        swap(arr1[i], arr1[i + gap]);

    // comparing elements in both arrays.
    for (j = gap > n ? gap - n : 0;
         i < n && j < m;
         i++, j++)
      if (arr1[i] > arr2[j])
        swap(arr1[i], arr2[j]);

    if (j < m)
    {
      // comparing elements in the second array.
      for (j = 0; j + gap < m; j++)
        if (arr2[j] > arr2[j + gap])
          swap(arr2[j], arr2[j + gap]);
    }
  }
}

// { Driver Code Starts.

int main()
{

  int T;
  cin >> T;

  while (T--)
  {
    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
    {
      cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
      cin >> arr2[i];
    }

    merge(arr1, arr2, n, m);

    for (int i = 0; i < n; i++)
      printf("%d ", arr1[i]);

    for (int i = 0; i < m; i++)
      printf("%d ", arr2[i]);

    cout << endl;
  }

  return 0;
}