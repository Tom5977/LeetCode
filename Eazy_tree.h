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
		//访问左子树
		if (!isValidBST(root->left))
			return false;
		//访问当前节点：如果当前节点小于等于中序遍历的前一个节点直接返回false。
		if (prev != NULL && prev->val >= root->val)
			return false;
		prev = root;
		//访问右子树
		if (!isValidBST(root->right))
			return false;
		return true;

	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		//从两个子节点开始判断
		return isSymmetricHelper(root->left, root->right);
	}

	bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
		//如果左右子节点都为空，说明当前节点是叶子节点，返回true
		if (left == NULL && right == NULL)
			return true;
		//如果当前节点只有一个子节点或者有两个子节点，但两个子节点的值不相同，直接返回false
		if (left == NULL || right == NULL || left->val != right->val)
			return false;
		//然后左子节点的左子节点和右子节点的右子节点比较，左子节点的右子节点和右子节点的左子节点比较
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