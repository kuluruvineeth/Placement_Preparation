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
        i = right+B;
    }
    return count;
}

int main()
{
    vector<int> A={1,1,1,1,1,0,0};
    cout<<solve(A,3)<<endl;
    return 0;
}
```

## 4. [Maximum Sum Triplet](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/maximum_sum_triplet.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n=A.size();
    //finding best on right side
    vector<int> suffix(n);
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1) suffix[i]=A[i];
        else suffix[i] = max(suffix[i+1],A[i]);
    }
    //finding best on left side
    set<int> s;
    s.insert(A[0]);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if(it!=s.begin() && suffix[i]!=A[i])
            ans = max(ans,(*--it)+A[i]+suffix[i]);
        
    }
    return ans;
}

int main()
{
    vector<int> v = {2,5,3,1,4,9};
    cout<<"Max triplet sum is : "<<solve(v)<<endl;
    return 0;
}
```

## 5. [Maximum Sum Contiguous Subarray](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/maximum_contiguous_subarray.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int maxsumSubArray(vector<int> &A)
{
    int n=A.size(),res,m=0;
    res=A[0];
    if(n==1) return res;
    for(int i=0;i<n;i++)
    {
        m=m+A[i];
        if(m<A[i])
        {
            m=A[i];
        }
        if(res < m) res=m;
    }
    return res;
}

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum subarray sum is : "<<maxsumSubArray(v)<<endl;
    return 0;
}
```

## 6. [Add one to number](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/maximum_contiguous_subarray.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &v)
{
    int i,n=v.size(),count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==9)
        {
            count++;
        }
        else break;
    }
    if(count==n)
    {
        vector<int> r;
        r.push_back(1);
        for(int i=0;i<n;i++)
        {
            r.push_back(0);
        }
        return r;
    }
    else if(v[n-1]==9)
    {
        int carry=1;
        for(i=n-1;i>=0 && carry==1;i--)
        {
            if(v[i]==9)
            {
                v[i]=0;
            }
            else
            {
                v[i]++;
                carry=0;
            }
        }
    }
    else v[n-1]++;
    //to remove leading zeros if any
    reverse(v.begin(),v.end());
    for(i=n-1;i>=0&&v[i]==0;i--) v.pop_back();
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    vector<int> v = {1,2,9};
    vector<int> ans = plusOne(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
```

## 7. [Maximum Absolute Difference](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/maximum_absolute_difference.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> &A)
{
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,max4=INT_MIN;
    assert(!A.empty());
    int ans = INT_MIN;
    int size = A.size();
    for(auto i=0;i<size;i++)
    {
        max1=max(max1,A[i]+i);
        max2=max(max2,-A[i]+i);
        max3=max(max3,A[i]-i);
        max4=max(max4,-A[i]-i);
    }
    for(auto i=0;i<size;i++)
    {
        ans=max(ans,max1-A[i]-i);
        ans=max(ans,max2+A[i]-i);
        ans=max(ans,max3-A[i]+i);
        ans=max(ans,max4+A[i]+i);
    }
    return ans;
}
int main()
{
    vector<int> v = {1,3,-1};
    cout<<"Maximum Absolute Difference is : "<<maxDiff(v)<<endl;
    return 0;
}
```

## 8. [Partitions](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/partitions.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int solve(int A,vector<int> &B)
{
    int total=0;
    for(int i=0;i<A;i++)
    {
        total+=B[i];
    }
    if(total%3!=0)
    {
        return 0;
    }
    int one_third_sum = total/3;
    int two_third_sum = 2*one_third_sum;
    int count=0;
    int sum=0;
    int one_third_count=0;
    for(int i=0;i<A-1;i++)
    {
        sum+=B[i];
        if(sum==two_third_sum)
        {
            count += one_third_count;
        }
        if(sum==one_third_sum)
        {
            one_third_count++;
        }
    }
    return count;
}

int main()
{
    vector<int> v = {1,2,3,0,3};
    cout<<"Partitions are : "<<solve(5,v)<<endl;
    return 0;
}
```

## 9. [Flip](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/flip.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> flip(string A)
{
    vector<int> ans;
    int n=A.size();
    bool flag=true;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        if(A[i]=='0')
        {
            arr[i]=1;
            flag=false;
        }
        else
        {
            arr[i]=-1;
        }
    }
    if(flag) return ans;
    ans.resize(2);
    int currentSum=0,maxSum=0,left=0,right=0;
    for(int i=0;i<n;i++)
    {
        currentSum += arr[i];
        if(currentSum>maxSum)
        {
            right=i;
            maxSum=currentSum;
            ans[0]=left+1;
            ans[1]=right+1;
        }
        if(currentSum<0)
        {
            left=i+1;
            currentSum=0;
        }
    }
    return ans;
}

int main()
{
    string A;
    cin>>A;
    vector<int> ans = flip(A);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
```

## 10. [Sort arrays with squares](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/sort_arrays_with_squares.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{
    int s=0,e=A.size()-1;
    vector<int> res;
    while(s<=e)
    {
        if(s==e)
        {
            res.push_back(A[s]*A[s]);
            break;
        }
        if(abs(A[s])>abs(A[e]))
        {
            res.push_back(A[s]*A[s]);
            s++;
        }
        else if(abs(A[s])<abs(A[e]))
        {
            res.push_back(A[e]*A[e]);
            e--;
        }
        else
        {
            res.push_back(A[s]*A[s]);
            s++;
            res.push_back(A[e]*A[e]);
            e--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    vector<int> v = {-6,-3,-1,2,4,5};
    vector<int> ans = solve(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
```

## 11. [Rotate matrix by 90degrees](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/rotate_matrix_by_90degrees.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

void rotate90Clockwise(vector<vector<int>> &v)
{
    //Transpose of matrix
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v[i].size();j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }
    //Reverse individual rows
    for(int i=0;i<v.size();i++)
    {
        int low=0,high=v.size()-1;
        while(low<high)
        {
            swap(v[i][low],v[i][high]);
            low++;
            high--;
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate90Clockwise(v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```

## 12. [Next Permutation](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/next_permutation.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A)
{
    int idx=-1;
    int n=A.size();
    for(int i=n-1;i>0;i--)
    {
        if(A[i]>A[i-1])
        {
            idx=i;
            break;
        }
    }
    if(idx==-1)
    {
        reverse(A.begin(),A.end());
    }
    else
    {
        int prev=idx;
        for(int i=idx+1;i<n;i++)
        {
            if(A[i]>A[idx-1] and A[i]<=A[prev])
            {
                prev=i;
            }
        }
        swap(A[idx-1],A[prev]);
        reverse(A.begin()+idx,A.end());
    }
    return A;
}

int main()
{
    vector<int> v = {1,2,3};
    vector<int> ans = nextPermutation(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
```

## 13. [Find Permutation](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/find_permutation.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> findPerm(string A,int B)
{
    int small=1;
    int large=B;
    vector<int> ans;
    for(int i=0;i<=A.size();i++)
    {
        if(A[i]=='I')
        {
            ans.push_back(small);
            small++;
        }
        else
        {
            ans.push_back(large);
            large--;
        }
    }
    return ans;
}

int main()
{
    vector<int> res = findPerm("ID",3);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}
```

## 14. [Wave Array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/wave_array.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

vector<int> wave(vector<int> &A)
{
    sort(A.begin(),A.end());
    int size = A.size();
    if(A.size()%2!=0)
    {
        size = size-1;
    }
    for(int i=0;i<size;i+=2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}

int main()
{
    vector<int> v = {1,2,3,4};
    vector<int> ans = wave(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
```

## 15. [Noble Integer](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Arrays/noble_integer.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int nobleInteger(vector<int> &A)
{
    int n=A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1]) continue;
        if(A[i]==n-i-1) return 1;
    }
    if(A[n-1]==0) return 1;
    return -1;
}

int main()
{
    vector<int> v = {3,2,1,3};
    cout<<nobleInteger(v)<<endl;
    return 0;
}
```