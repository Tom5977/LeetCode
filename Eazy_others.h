#pragma once
#include "Header.h"

class Shuffle {
public:
	vector<int> num;

	Shuffle(vector<int>& nums) {
		num = nums;
	}

	vector<int> reset() {
		return num;
	}

	vector<int> shuffle() {
		int size = num.size();
		vector<int> nums(num), re;
		for (int i = size; i > 0; i--)
		{
			int r = rand() % i;
			re.push_back(nums[r]);
			nums.erase(nums.begin() + r);
		}
		return re;
	}
};

class MinStack {
private:
	vector<int> minStack;
public:
	MinStack() {};
	void push(int n) {
		minStack.push_back(n);
	}
	void pop() {
		minStack.pop_back();
	}
	int top() {
		return *minStack.end();
	}
	int getMin() {
		int min = minStack[0];
		for (int i = 0; i < minStack.size(); i++)
		{
			if (minStack[i] < min)
			{
				min = minStack[i];
			}
		}
		return min;
	}
};

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string>re;
		for (int i = 1; i <= n; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				re.push_back("FizzBuzz");
			}
			else if (i % 3 == 0)
			{
				re.push_back("Fizz");
			}
			else if (i % 5 == 0)
			{
				re.push_back("Buzz");
			}
			else
			{
				re.push_back(to_string(i));
			}
		}
		return re;
	}

	int countPrimes(int n) {
		bool *arr = new bool[n]();
		int cnt = 0;
		for (int i = 2; i < n; i++)
		{
			if (arr[i])
			{
				continue;
			}
			cnt++;
			for (int j = i; j < n; j += i)
			{
				arr[j] = true;
			}
		}
		return cnt;
	}

	bool isPowerOfThree(int n) {
		/*if (n == 0)
		{
			return false;
		}
		double m = n;
		double r = log(m) / log(3);

		if ((int)r == r)
		{
			if (n < 0 && (int)r % 2 == 0)
			{
				return false;
			}
			return true;
		}
		return false;*/
		if (n < 1)
		{
			return false;
		}
		while (n > 1)
		{
			if (n % 3 == 0)
			{
				n /= 3;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	int romanToInt(string s) {
		map<string, int> roma;
		roma["I"] = 1;
		roma["IV"] = 4;
		roma["IX"] = 9;
		roma["V"] = 5;
		roma["X"] = 10;
		roma["XL"] = 40;
		roma["XC"] = 90;
		roma["L"] = 50;
		roma["C"] = 100;
		roma["CD"] = 400;
		roma["CM"] = 900;
		roma["D"] = 500;
		roma["M"] = 1000;
		int size = s.size(), sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (roma.find(s.substr(i,2)) != roma.end())
			{
				sum += roma[s.substr(i, 2)];
				i++;
			}
			else
			{
				sum += roma[s.substr(i, 1)];
			}
		}
		return sum;
	
	}

	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n != 0)
		{
			if (n % 2 == 1)
			{
				cnt++;
			}
			n = n >> 1;
		}
		return cnt;
	}

	int hammingDistance(int x, int y) {
		int cnt = 0;
		while (x != 0 ||y != 0)
		{
			if (x % 2 != y % 2)
			{
				cnt++;
			}
			x /= 2;
			y /= 2;
		}
		return cnt;
	}

	uint32_t reverseBits(uint32_t n) {
		uint32_t re = 0;
		for (int i = 0; i < 32; i++)
		{
			re += n % 2 == 1 ? pow(2, 31 - i) : 0;
			n /= 2;
		}
		return re;
	}

	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> re;
		vector<int> first = { 1 };
		vector<int> bas = { 1, 1 };
		re.push_back(first);
		
		if (numRows > 1)
		{	
			re.push_back(bas);
			for (int i = 2; i < numRows; i++)
			{
				vector<int> tmp = { 1 };
				for (int j = 0; j < bas.size() - 1; j++)
				{
					tmp.push_back(bas[j] + bas[j + 1]);
				}
				tmp.push_back(1);
				re.push_back(tmp);
				bas = tmp;
			}
		}
		return re;

	}

	bool isValid(string s) {
		vector<char> x;
		for (int i = 0; i < s.size(); i++)
		{
			if (x.size() != 0)
			{
				if (x[x.size() - 1] == '(' && s[i] == ')' 
				|| x[x.size() - 1] == '[' && s[i] == ']'
				|| x[x.size() - 1] == '{' && s[i] == '}')
				{
					x.pop_back();
				}
				else
				{
					x.push_back(s[i]);
				}
			}
			else
			{
				x.push_back(s[i]);

			}
			
			
		}
		if (x.empty())
		{
			return true;
		}
		return false;
	}

	int missingNumber(vector<int>& nums) {
		int sum = 0, size = nums.size();
		for (int i = 0; i < size; i++)
		{
			sum += nums[i];
		}
		return (1 + size) * size / 2 - sum;

	}
};