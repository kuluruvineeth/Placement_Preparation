/*
Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “abcd” and “dabc” are an anagram of each other.
*/
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