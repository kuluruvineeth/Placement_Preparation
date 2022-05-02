# List of Strings Questions for Interview Preparation

## 1. [Anagram](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/anagram.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

/*There are two approaches to solve this problem.
1.Naive approach : sort both strings and then compare each of the letter in both strings simultaneously,if they match yes else no
2.Optimal approach : use hashing,for first string increment the count in array for respective slots,for second string decrement the count in array for respective slots,finally if all slots in array are 0,then they are anagrams.
*/


//1.NAIVE APPROACH : TIME = O(N*LOGN) , SPACE = O(1)

bool anagram_naive(string &s1,string &s2)
{
	int n1=s1.length();
	int n2=s2.length();

	if(n1!=n2)
	{
		return false;
	}

	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	
	for(int i=0;i<n1;i++)
	{
		if(s1[i]!=s2[i])
		{
			return false;
		}
	}
	return true;
}

//2.OPTIMAL APPROACH : TIME = O(N) , SPACE = O(N)

bool anagram_optimal(string &s1,string &s2)
{
	int n1=s1.length();
	int n2=s2.length();

	if(n1!=n2)
	{
		return false;
	}

	vector<int> hash1(26,0);
	//vector<int> hash2(26,0);
	/*for(int i=0;i<n1;i++)
	{
		hash1[s1[i]]+=1;
		hash2[s2[i]]+=1;
	}*/
	
	for(int i=0;i<n1;i++)
	{
		hash1[s1[i]]+=1;
		hash1[s2[i]]-=1;
	}

	/*for(int i=0;i<26;i++)
	{
		if(hash1[i]!=hash2[i])
		{
			return false;
		}
	}*/

	for(int i=0;i<26;i++)
	{
		if(hash1[i])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string s1="vinni";
	string s2="innvi";
	cout<<anagram_naive(s1,s2)<<endl;;
	cout<<anagram_optimal(s1,s2);
	cout<<endl;
}
```

## 2. [Parenthesis Checker](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/parenthesis_checker.cpp)
```cpp
/*
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.

Example: 

Input: exp = “[()]{}{[()()]()}” 
Output: Balanced
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack<char> st;
        int n = s.size();
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]=='}')
            {
                if(!st.empty())
                {
                    if(st.top()=='{')
                    {
                        st.pop();
                    }
                    else
                    {
                        flag=0;
                    }
                }
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        flag=0;
                    }
                }
            }
            else if(s[i]==']')
            {
                if(!st.empty())
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        flag=0;
                    }
                }
            }
        }
        if(st.empty() & flag)
        {
            cout<<"balanced"<<endl;
        }
        else
        {
            cout<<"not balanced"<<endl;
        }
    }
}
```

## 3. [Reverse words in string](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/reverse_words_in_string.cpp)
```cpp
/*
Example: Let the input string be “i.like.this.program.very.much”. The function should change the string to “much.very.program.this.like.i”
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        stack<string> st;
        cin>>s;
        string temp;
        temp="";
        int ctr=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '.')
            {
                temp = temp + s[i];
            }
            else
            {
                st.push(temp);
                temp="";
                ctr++;
            }
            if(i == s.size()-1)
            {
                st.push(temp);
                temp="";
                ctr++;
            }
        }
        ctr--;
        while(!st.empty())
        {
            cout<<st.top();
            st.pop();
            if(ctr!=0)
            {
                cout<<".";
                ctr--;
            }
        }
        cout<<endl;
    }
}
```

## 4. [Longest Common Substring](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/longest_common_substring.cpp)
```cpp
/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 
Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.
*/
#include<bits/stdc++.h>
using namespace std;

int LCStr(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    int result = 0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        int m,n;
        cin>>m>>n;
        cin>>s1>>s2;
        cout<<LCStr(s1,s2,m,n)<<endl;
    }
}
```

## 5. [Longest Common Prefix](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/longest_common_prefix.cpp)
```cpp
/*
Given a set of strings, find the longest common prefix. 
Examples:
Input  : {"apple", "ape", "april"}
Output : "ap"
*/
#include<bits/stdc++.h>
using namespace std;

int minLen(vector<string> v)
{
    int len = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        int strsize = v[i].size();
        len = min(len,strsize);
    }
    return len;
}

int check(vector<string> v,int mid)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<mid;j++)
        {
            if(v[i][j] != v[0][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        int minlen = minLen(v);
        int l=1,h=minlen,ans=-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(check(v,mid))
            {
                l = mid+1;
                ans = mid;
            }
            else
            {
                h = mid - 1;
            }
        }
        for(int i=0;i<ans;i++)
        {
            cout<<v[0][i];
        }
        if(ans == -1)
        {
            cout<<-1;
        }
        cout<<endl;
    }
}
```