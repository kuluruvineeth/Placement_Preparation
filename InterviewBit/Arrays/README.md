# List of Array Topic Questions from Interviewbit

## 1.[Pick from both sides](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/pick_from_both_sides.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

//It is not working for few test cases
int solution(vector<int> &A,int B)
{
   int n=A.size();
   int currentSum=0;
   for(int i=0;i<B;i++)
   {
       currentSum += A[i];
   }
   int maxSum = currentSum;
   int include=n-1,exclude=B-1;
   while(exclude>=0 && include>=0)
   {
       currentSum += A[exclude--];
       currentSum -= A[include--];
       maxSum = max(currentSum,maxSum);
   }
   return maxSum;
}

//working for all test cases(IMP:Prefix array concept)
int solution1(vector<int> &v,int B)
{
    int n=v.size();
    vector<int> prefixSumArray(n,0);
    for(int i=0;i<n;i++)
    {
        prefixSumArray[i] = v[i] + (i==0 ? 0:prefixSumArray[i-1]); 
    }
    int left=B-1,right=n-1,sum=INT_MIN;
    while(left>=-1)
    {
        sum = max(sum, (left>=0 ? prefixSumArray[left]:0)+prefixSumArray[n-1]-prefixSumArray[right-1]);
        left--;right--;
    }
    return sum;
}

int main()
{
    vector<int> v={-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35, -810, 842, -712, -894, 40, -58, 264, -352, 446, 805, 890, -271, -630, 350, 6, 101, -607, 548, 629, -377, -916, 954, -244, 840, -34, 376, 931, -692, -56, -561, -374, 323, 537, 538, -882, -918, -71, -459, -167, 115, -361, 658, -296, 930, 977, -694, 673, -614, 21, -255, -76, 72, -730, 829, -223, 573, 97, -488, 986, 290, 161, -364, -645, -233, 655, 574, -969, -948, 350, 150, -59, 724, 966, 430, 107, -809, -993, 337, 457, -713};
    cout<<solution1(v,118)<<endl;
    return 0;
}
```

## 2. [Minimum steps in infinite grid](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/min_steps_infinite_grid.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int minSteps(vector<int> &A,vector<int> &B)
{
    int steps = 0;
    for(int i=0;i<A.size()-1;i++)
    {
        int x = A[i];
        int y = B[i];
        int x1 = A[i+1];
        int y1 = B[i+1];
        int x_diff = abs(x-x1);
        int y_diff = abs(y-y1);
        steps += max(x_diff,y_diff);
    }
    return steps;
}

int main()
{
    vector<int> A={0,1,2};
    vector<int> B={0,1,2};
    cout<<minSteps(A,B)<<endl;
    return 0;
}
```

## 3. [Minimum lights to activate](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/min_lights_to_activate.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A,int B)
{
    int count=0;
    int n=A.size(),i=0;
    while(i<n)
    {
        int left = max(i-B+1,0);
        int right = min(i+B-1,n-1);
        bool bulbFound=0;
        while(right>=left)
        {
            if(A[right--]==1)
            {
                bulbFound = 1;
                break;
            }
        }
        if(!bulbFound) return -1;
        count++;
        i = right+B-1;
    }
    return count;
}

int main()
{
    vector<int> A={0,0,1,1,1,0,0,1};
    cout<<solve(A,3)<<endl;
    return 0;
}
```