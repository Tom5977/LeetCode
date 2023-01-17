#pragma once
#include "Header.h"

class solution_sortAndSearch {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int num = nums1.size();
		for (int i = 0; i < num - m; i++)
		{
			nums1.pop_back();
		}
		int i = 0, j = 0;
		while (i < m && j < n)
		{
			if (nums2[j] < nums1[i])
			{
				nums1.insert(nums1.begin() + i, nums2[j]);
				j++;
				m++;
				nums1.pop_back();
			}
				i++;
		}
		if (i == m)
		{
			
			for  (; j < n; j++)
			{
				nums1.push_back(nums2[j]);
			}
		}
	}

	bool isBadVersion(int version){}
	int firstBadVersion(int n) {
		int start = 1, end = n;
		while (start < end) {
			int mid = start + (end - start) / 2;
			if (!isBadVersion(mid))
				start = mid + 1;
			else
				end = mid;
		}
		return start;


	}
	
	
};