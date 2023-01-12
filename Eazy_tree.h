#pragma once
#include "Header.h"

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class solution_tree
{
public:
	int maxDepth(TreeNode* root) {
		TreeNode* t = root;
		if (t == NULL)
		{
			return 0;
		}
		int lh = 1 + maxDepth(t->left);
		int rh = 1 + maxDepth(t->right);
		return lh > rh ? lh : rh;
	};

	TreeNode* prev = NULL;
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;
		//����������
		if (!isValidBST(root->left))
			return false;
		//���ʵ�ǰ�ڵ㣺�����ǰ�ڵ�С�ڵ������������ǰһ���ڵ�ֱ�ӷ���false��
		if (prev != NULL && prev->val >= root->val)
			return false;
		prev = root;
		//����������
		if (!isValidBST(root->right))
			return false;
		return true;

	}


};