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
class Solution {
public:
    // Pre-order traversal and flip the left and right
    // subtree at each root.
    TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return root;
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
    }
};
