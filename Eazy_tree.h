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

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		//�������ӽڵ㿪ʼ�ж�
		return isSymmetricHelper(root->left, root->right);
	}

	bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
		//��������ӽڵ㶼Ϊ�գ�˵����ǰ�ڵ���Ҷ�ӽڵ㣬����true
		if (left == NULL && right == NULL)
			return true;
		//�����ǰ�ڵ�ֻ��һ���ӽڵ�����������ӽڵ㣬�������ӽڵ��ֵ����ͬ��ֱ�ӷ���false
		if (left == NULL || right == NULL || left->val != right->val)
			return false;
		//Ȼ�����ӽڵ�����ӽڵ�����ӽڵ�����ӽڵ�Ƚϣ����ӽڵ�����ӽڵ�����ӽڵ�����ӽڵ�Ƚ�
		return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> re;
		queue<TreeNode*> q;
		if (root == NULL)
		{
			return re;
		}
		q.push(root);
		while (!q.empty())
		{
			queue<TreeNode*> p;
			vector<int> row;
			while (!q.empty())
			{
				
				TreeNode* tmp = q.front();
				q.pop();
				row.push_back(tmp->val);
				if (tmp->left != NULL)
				{
					p.push(tmp->left);
				}
				if (tmp->right != NULL)
				{
					p.push(tmp->right);
				}
			}
			re.push_back(row);
			q = p;
		}
		return re;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return NULL;
		}
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (start >end)
		{
			return NULL;
		}
		int mid = (start + end) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, start, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, end);
		return root;
	}

};