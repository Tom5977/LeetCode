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
};