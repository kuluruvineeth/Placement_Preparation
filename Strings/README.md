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