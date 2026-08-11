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
    // IDEA: 4 conditions for a tree to be a BST
    // 1. the minimum element in the right subtree is bigger than root
    // 2. the maximum element in the left subtree is smaller than root
    // 3. the left subtree is a BST
    // 4. the right subtree is a BST
    //
    // Find minElement in a tree by walking always left. the right for finding max
    bool isValidBST(TreeNode* root) {
	if (!root || (!root->left && !root->right))
	    return true;
	if (root->left && getMaxElement(root->left) >= root->val)
	    return false;
	if (root->right && getMinElement(root->right) <= root->val)
	    return false;
	return isValidBST(root->left) && isValidBST(root->right);
    }

    int getMinElement(TreeNode* root) {
	if (!root->left)
	    return root->val;
	return getMinElement(root->left);
    }

    int getMaxElement(TreeNode* root) {
	if (!root->right)
	    return root->val;
	return getMaxElement(root->right);
    }
};
