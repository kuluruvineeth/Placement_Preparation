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

## 6. [Longest Palindromic Substring](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/longest_palindromic_substring.cpp)
```cpp
/*
Given a string, find the longest substring which is palindrome. 
For example, 
Input: Given string :"forgeeksskeegfor", 
Output: "geeksskeeg"
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
        int l,h;
        int maxAns = -1;
        int start=-1,end=-1;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            //Even Length
            l=i-1;
            h=i;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1 > maxAns)
                {
                    maxAns = h-l+1;
                    start = l;
                    end = h;
                }
                l--;
                h++;
            }
            //Odd Length
            l=i-1;
            h=i+1;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1 > maxAns)
                {
                    maxAns = h-l+1;
                    start = l;
                    end = h;
                }
                l--;
                h++;
            }
        }
        if(maxAns == -1)
        {
            start = 0;
            end = 0;
        }
        for(int i=start;i<=end;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}
```

## 7. [Min Inserions to form palindrome](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/min_insertions_to_form_palindrome.cpp)
```cpp
/*
Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.
ab: Number of insertions required is 1 i.e. bab
*/
#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,int m,int n)
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
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
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
        int n;
        cin>>s1;
        n = s1.size();
        s2 = s1;
        reverse(s2.begin(),s2.end());
        cout<<n - LCS(s1,s2,n,n) << endl;
    }
}
```

## 8. [String rotated by two places](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/string_rotated_by_two_places.cpp)
```cpp
/*
Given two strings, the task is to find if a string can be obtained by rotating another string two places. 
Examples: 
Input: string1 = “amazon”, string2 = “azonam” 
Output: Yes
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,a1,a2;
        cin>>a;
        a1="";
        a2="";
        cin>>b;
        int l=a.size();
        a1 = a1 + a.substr(2) + a.substr(0,2);
        a2 = a2 + a.substr(l-2) + a.substr(0,l-2);
        if(a1 == b || a2 == b)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
}
```

## 9. [Remove duplicates](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/remove_duplicates.cpp)
```cpp
/*
Given a string S, the task is to remove all the duplicates in the given string. 
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
        int hash[260] = {0};
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(hash[s[i]]==0)
            {
                cout<<s[i];
                hash[s[i]]++;
            }
        }
        cout<<endl;
    }

}
```

## 10. [Reverse String](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/reverse_string.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int len = s.size();
    for(int i=0;i<len/2;i++)
    {
        swap(s[i],s[len-i-1]);
    }
}

int main()
{
    vector<char> v = {'h','e','l','l','o'};
    reverseString(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
```

## 11. [Is string palindrome](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/is_palindrome.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s)
{
    int len = s.size();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1]) return 0;
    }
    return 1;
}

int main()
{
    string s = "abba";
    if(isPalindrome(s)) cout<<"string is palindrome"<<endl;
    else cout<<"string is not plaindrome"<<endl;
    return 0;
}
```

## 12. [Duplicate characters in string](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/duplicate_chars_in_string.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

void print_duplicates(string s)
{
    int arr[256]; //256 as its not said there would be only alphabets
    memset(arr,0,sizeof(arr));
    for(char c:s)
    {
        arr[c - 'a']++;
    }
    for(int i=0;i<256;i++)
    {
        if(arr[i]>1)
        {
            cout<<('a' + i)<<" Count="<<arr[i]<<endl;
        }
    }
}

//using maps
void print_duplicates1(string s)
{
    map<char,int> mp;
    for(char c:s)
    {
        mp[c]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second > 1)
        {
            cout<<i->first<<" Count="<<i->second<<endl;
        }
    }
}

int main()
{
    string s = "geeksforgeeks";
    print_duplicates(s);
    print_duplicates1(s);
}
```

## 13. [Check string is rotation of other](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/check_rotation_of_other.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

void check_rotated(string a, string b)
{
    a += a;
    //now string b must be sub-string of a.
    //find will return 0th based index from where the substring will start
    if(a.find(b) != string::npos) cout<<"YES";
    else cout<<"NO";
}

int main()
{
    check_rotated("abcd","cdab");
    return 0;
}
```

## 14. [String shuffle of other](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/string_shuffle_of_other.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;
/*
    Check if a string is a valid shuffle of two other strings:
    for eg. 1XY2 is a valid shuffle of XY and 12, Y12X is not a valid shuffle of XY and 12
    as in y12x the order of string is changed.
*/
void check_shuffle_of_2_string()
{
    string a="xy", b="12";
    /*
        if    string s2 = "1xy2"; it is valid as it has maintained order of both string
        if    string s2 = "2xy1" is invalid here "xy" is maintained but not "12"
        if    string s2 = "y1x2" is invalid here "12" is maintained but not "xy"
    */
   string s2="x12y";
   int i=0,j=0;
   for(auto x: s2)
   {
       if(i<a.size() && x == a[i]) i++;
       else if(j<b.size() && x == b[j]) j++;
   }
   if(s2.size() == i+j && i==a.size() && j==b.size()) cout<<"yes"<<endl;
   else cout<<"no"<<endl;
}

int main()
{
    check_shuffle_of_2_string();
    return 0;
}
```

## 15. [Count and Say](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Strings/count_and_say.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if(n==1) return "1";
    if(n==2) return "11";
    string s="11";
    for(int i=3;i<=n;i++)
    {
        string t="";
        s=s+'&';
        int count=1;
        for(int j=1;j<s.length();j++)
        {
            if(s[j]!=s[j-1])
            {
                t=t+to_string(count);
                t=t+s[j-1];
                count=1;
            }
            else count++;
        }
        s=t;
    }
    return s;
}

int main()
{
    cout<<countAndSay(4)<<endl;
    return 0;
}
```