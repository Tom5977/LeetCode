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
};