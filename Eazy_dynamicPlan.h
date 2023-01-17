#pragma once
#include "Header.h"

class solution_dynamicPlan {
	int climbStairs(int n) {
		/*if (n == 0)
		{
			return 1;
		}
		if (n == -1)
		{
			return 0;
		}
		return climbStairs(n - 1) + climbStairs(n - 2);*/
		if (n <= 1)
		{
			return 1;
		}
		int* p = new int[n];
		p[0] = 1;
		p[1] = 2;
		for (int i = 2; i < n; i++)
		{
			p[i] = p[i - 1] + p[i - 2];
		}
		return p[n - 1];
	}

	int maxProfit(vector<int>& prices) {
		int tmp = 0, max = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			tmp += prices[i] - prices[i - 1];
			if (tmp < 0)
			{
				tmp = 0;
			}
			if (tmp > max)
			{
				max = tmp;
			}
		}
		return max;
	}

	int maxSubArray(vector<int>& nums) {
		int tmp = 0, max = 0, minusMax = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			tmp += nums[i];
			if (tmp > minusMax)
			{
				minusMax = tmp;
			}
			if (tmp < 0)
			{
				tmp = 0;

			}
			if (tmp > max)
			{
				max = tmp;
			}
		}
		if (max == 0)
		{
			return minusMax;
		}
		return max;
	}

	int rob(vector<int>& nums) {
		//�߽������ж�
		if (nums.size() == 0)
			return 0;
		int length = nums.size();
		int dp0 = 0;//��1��û͵
		int dp1 = nums[0];//��1��͵��
		//�ӵ�2����ʼ�ж�
		for (int i = 1; i < length; i++) {
			//��ֹdp0���޸�֮��������������Ӱ�죬����
			//ʹ��һ����ʱ����temp�Ȱѽ����������������
			//֮���ٸ�ֵ��dp0.
			int temp = dp0 > dp1 ? dp0 : dp1;
			dp1 = dp0 + nums[i];
			dp0 = temp;
		}
		//���ȡ���ֵ����
		return dp0 > dp1 ? dp0 : dp1;

	}
};