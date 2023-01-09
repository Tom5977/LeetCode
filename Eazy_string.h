#pragma once
#include"Header.h"

class solution_string
{
public:
	void reverseString(vector<char>& s) {
		for (int i = 0; i < s.size() / 2; i++)
		{
			char tmp = s[i]; 
			s[i] = s[s.size() - 1 - i];
			s[s.size() - 1 - i] = tmp;
		}
	}

	int reverse(int x) {
		vector<int> re;
		int sigh = 1;
		if (x == 0)
		{
			return 0;
		}
		else if (x < 0)
		{
			sigh = -1;
			
		}

		while (x != 0)
		{
			re.push_back(x % 10);
			x = x / 10;
		}
		
		if (re.size() == 10)
		{
			bool outLimit = 1;
			vector<int> limit = { 2,1,4,7,4,8,3,6,4,7 };
			for (int i = 0; i < 9; i++)
			{
				if (abs(re[i]) > limit[i])
				{
					return 0;
				}
				else if (abs(re[i]) < limit[i])
				{
					outLimit = 0;
					break;
				}
			}
			if (outLimit != 0)
			{
				if (sigh == 1)
				{	
					if (abs(re[9]) > limit[9])
					{
						return 0;
					}
										
				}
				else
				{
					if (abs(re[9]) > limit[9] + 1)
					{
						return 0;
					}
					
				}
			}
			
		}
		int result = 0;
		for (int i = 0; i < re.size(); i++)
		{
			result += re[i] * pow(10, re.size() - 1- i);
		}
		return result;
	}

	int firstUniqChar(string s) {
		map<char, int>count;
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i]]++;
		}
		
		for (int i = 0; i < s.size(); i++)
		{
			if (count.find(s[i])->second == 1)
			{
				return i;
			}
			
		}
		return -1;
	}

	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
		{
			return false;
		}
		map<char, int> count1, count2;
		for (int i = 0; i < s.size(); i++)
		{
			count1[s[i]]++;
			count2[t[i]]++;
		}
		if (count1.size() != count2.size())
		{
			return false;
		}
		for (auto it1 = count1.begin(), it2 = count2.begin(); it1 != count1.end(); it1++, it2++)
		{
			if (it1->first == it2->first && it1->second == it2->second)
			{
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	bool isPalindrome(string s) {
		for (int i = 0; i < s.size(); i++)
		{
			if (!(isalpha(s[i]) || isdigit(s[i])))
			{
				s.erase(s.begin() + i);
				i--;
			}
			else if (isalpha(s[i]))
			{
				s[i] = tolower(s[i]);
			}
			
			
		}
		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i])
			{
				return false;
			}
		}
		return true;
	}

	int myAtoi(string s) {
		int i = 0, sigh = 0;
		vector<int> re;
		while (s[i] == ' ')
		{
			i++;
		}
		if (s[i] == '-')
		{
			sigh = -1;
			i++;
		}
		else if (s[i] == '+')
		{
			sigh = 1;
			i++;
		}
		else
		{
			sigh = 1;
		}
		while (s[i] == '0')
		{
			i++;
		}
		while (isdigit(s[i]))
		{
			re.push_back(s[i] - 48);
			i++;
		}
		
		int outLimit = -1;
		if (re.size() < 10)
		{
			outLimit = 0;
		}
		else if (re.size() == 10)
		{
			vector<int> limit = { 2,1,4,7,4,8,3,6,4,7 };
			for (int i = 0; i < 9; i++)
			{
				if (re[i] > limit[i])
				{
					outLimit = 1;
					break;
				}
				else if (re[i] < limit[i])
				{
					outLimit = 0;
					break;
				}
			}
			if (outLimit == -1)
			{
				if (sigh == 1)
				{
					if (re[9] >= limit[9])
					{
						outLimit = 1;
					}

				}
				else
				{
					if (re[9] >= limit[9] + 1)
					{
						outLimit = 1;
					}

				}
			}
		}
		else
		{
			outLimit = 1;
		}
		int result = 0;
		if (outLimit == 1)
		{
			if (sigh == 1)
			{
				return pow(2, 31) - 1;
			}
			else
			{
				return -pow(2, 31);
			}
		}
		else
		{
			
			for (int i = 0; i < re.size(); i++)
			{
				result += re[i] * pow(10, re.size() - 1 - i);
			}
		}
		return result * sigh;
		

	}

	int strStr(string haystack, string needle) {
		int i = 0, j = 0;
		if (haystack.size() >= needle.size())
		while (i <= haystack.size() - needle.size())
		{
			bool match = 1;
			for (int j = 0; j < needle.size(); j++)
			{
				if (haystack[i] != needle[j])
				{
					match = 0;
					i = i + 1 - j;
					break;
				}
				i++;
			}
			if (match == 1)
			{
				return i - needle.size();
			}
		}
		return -1;
	}
};