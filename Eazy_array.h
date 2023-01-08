#pragma once
#include"Header.h"

class solution_array 
{
public:

	int removeDuplicates(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1;)
		{
			if (nums[i] == nums[i + 1])
			{
				nums.erase(nums.begin() + i + 1);
			}
			else
			{
				i++;
			}
		}
		return nums.size();
	}

	int maxProfit(vector<int>& prices) {
		int sum = 0;
		for (int i = 0; i < prices.size() - 1; i++)
		{
			if (prices[i + 1] > prices[i])
			{
				sum += prices[i + 1] - prices[i];
			}
		}
		return sum;
	}

	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		int size = nums.size(), l = nums.size() - k;
		for (int i = 0; i < l / 2; i++)
		{
			int tmp = nums[l - 1 - i];
			nums[l - 1 - i] = nums[i];
			nums[i] = tmp;
		}
		for (int i = 0; i < k / 2; i++)
		{
			int tmp = nums[size - 1 - i];
			nums[size - 1 - i] = nums[l + i];
			nums[l + i] = tmp;
		}
		for (int i = 0; i < size / 2; i++)
		{
			int tmp = nums[size - 1 - i];
			nums[size - 1 - i] = nums[i];
			nums[i] = tmp;
		}
	}
	
	bool containsDuplicate(vector<int>& nums) {
		map<int, int>count;
		for (int i = 0; i < nums.size(); i++)
		{
			count[nums[i]]++;
			if (count[nums[i]] > 1)
			{
				return true;
			}
		}
		return false;
	}

	int singleNumber(vector<int>& nums) {
		set<int>count;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count.count(nums[i]) == 0)
			{
				count.insert(nums[i]);
			}
			else
			{
				count.erase(nums[i]);
			}
			
		}
		return *count.begin();
	}

	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int>count1, count2;
		for (int i = 0; i < nums1.size(); i++)
		{
			count1[nums1[i]]++;
		}
		for (int i = 0; i < nums2.size(); i++)
		{
			count2[nums2[i]]++;
		}
		auto it1 = count1.begin(), it2 = count2.begin();
		vector<int> result;
		while (it1 != count1.end() && it2 != count2.end())
		{
			if (it1->first == it2->first)
			{
				int mult = it1->second < it2->second ? it1->second : it2->second;
				for (int i = 0; i < mult; i++)
				{
					result.push_back(it1->first);
				}
				it1++;
				it2++;
			}
			else if (it1->first > it2->first)
			{
				it2++;
			}
			else
			{
				it1++;
			}
			
		}
		return result;
	}

	vector<int> plusOne(vector<int>& digits) {
		if (digits[0] == 0)
		{
			digits[0]++;
		}
		else
		{
			int i = digits.size() - 1;
			while (i >= 0 && digits[i] == 9)
			{
				digits[i] = 0;
				i--;
			}
			if (i == -1)
			{
				digits.insert(digits.begin(), 1);
			}
			else
			{
				digits[i]++;
			}

		}
		return digits;
	}

	void moveZeroes(vector<int>& nums) {
		
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				nums.erase(nums.begin() + i);
				count++;
				i--;
			}
		}
		for (int i = 0; i < count; i++)
		{
			nums.push_back(0);
		}
	}	

	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>sortedNums(nums);
		sort(sortedNums.begin(), sortedNums.end());
		for (int j = 1; j < sortedNums.size(); j++)
		{
			if (sortedNums[j - 1] + sortedNums[j] >= target)
			{
				for (int i = j - 1; i >= 0; i--)
				{
					if (sortedNums[i] + sortedNums[j] == target)
					{
						vector<int>result;
						
						
						for (int k = 0; k < nums.size(); k++)
						{
							if (nums[k] == sortedNums[i] || nums[k] == sortedNums[j])
							{
								result.push_back(k);
							}
						}
						
						return result;
					}
				}
			}
		}
		return nums;
		
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		set<char> check;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				
				if (board[i][j] != '.')
				{
					if (check.count(board[i][j]) == 1)
					{
						return false;
					}
					else
					{
						check.insert(board[i][j]);
					}
				}
			}
			check.clear();
			for (int j = 0; j < 9; j++)
			{
				
				if (board[j][i] != '.')
				{
					if (check.count(board[j][i]) == 1)
					{
						return false;
					}
					else
					{
						check.insert(board[j][i]);
					}
				}
			}
			check.clear();
			for (int j = 0; j < 9; j++)
			{
				
				char tmp = board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3];
				if (tmp != '.')
				{
					if (check.count(tmp) == 1)
					{
						return false;
					}
					else
					{
						check.insert(tmp);
					}
				}
			}
			check.clear();
		}
		return true;
	}

	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		for (int i = 0; i < size / 2; i++)
		{
			for (int j = i; j < size - 1 - i; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[size - 1 - j][i];
				matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
				matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
				matrix[j][size - 1 - i] = tmp;
			}
		}
	}
};

