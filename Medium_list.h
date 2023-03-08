#pragma once
#include "Header.h"

class MSolution_list {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> re;
		sort(nums.begin(), nums.end());
		int i = 0, size = nums.size();
		while (nums[i] <= 0 && i < size - 2)
		{
			if (i > 0 && nums[i] == nums[i - 1])
			{
				i++;
				continue;
			}
			int l = i + 1, r = size - 1;
			while (l < r)
			{
				int sum = nums[l] + nums[r];
				if (sum == -nums[i])
				{
					vector<int> tmp = { nums[i], nums[l], nums[r] };
					re.push_back(tmp);

					while (l < r && nums[l] == nums[l + 1])
						l++;
					while (l < r && nums[r] == nums[r - 1])
						r--;
					l++;
					r--;
				}
				else if (sum < -nums[i])
				{
					l++;
				}
				else
				{
					r--;
				}
				
			}
			i++;
		}
		return re;
	}

	void setZeroes(vector<vector<int>>& matrix) {
		set<int> r, c;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					r.insert(i);
					c.insert(j);
				}
			}
		}
		for (auto it : r)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				matrix[it][j] = 0;
			}
		}
		for (auto it : c)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				matrix[i][it] = 0;
			}
		}
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> tmp(strs);
		for (int i = 0; i < tmp.size(); i++)
		{
			sort(tmp[i].begin(), tmp[i].end());
		}
		map<string, int> save;
		vector<vector<string>> re;
		int c = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (save.find(tmp[i]) == save.end())
			{
				save[tmp[i]] = c;
				c++;
				vector<string> row = { strs[i] };
				re.push_back(row);
			}
			else
			{
				re[save[tmp[i]]].push_back(strs[i]);
			}
		}
		return re;
	}

	int lengthOfLongestSubstring(string s) {
		vector<char> tmp;
		int max = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] == s[i])
				{
					vector<char> chg(tmp.begin() + j + 1, tmp.end());
					tmp = chg;
					break;
				}
			}
			tmp.push_back(s[i]);
			if (tmp.size() > max)
			{
				max = tmp.size();
				
			}
		}
		return max;
	}

	string longestPalindrome(string s) {
		return s;
	}
};