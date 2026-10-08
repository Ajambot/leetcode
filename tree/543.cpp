/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// IDEA: longest path between two nodes passing by root is = height(left) + height(right).
// Since the diameter may not pass by root, recursively check diameter of subtrees.
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
	if (!root) return 0;
	int curDiameter = height(root->left) + height(root->right);
	return max({diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right), curDiameter});
    }

    int height(TreeNode* root) {
	if (!root) {
	    return 0;
	}
	return 1 + max(height(root->left), height(root->right));
    }
};
