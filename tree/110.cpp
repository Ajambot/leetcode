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
    // Find the height of the left and right subtrees and check if they differ by more than one,
    // if they do the whole tree is unbalanced. Otherwise keep recursively checking the left
    // and right subtrees
    bool isBalanced(TreeNode* root) {
	if (root == NULL) {
	    return true;
	}

	if (abs(height(root->left)-height(root->right))>1) {
	    return false;
	}

	return isBalanced(root->left) && isBalanced(root->right);
    }

    // The height of a tree is equal to the max height between its left and right subtrees + 1
    // An empty node has height -1 (this also means that leaf nodes have height 0)
    int height(TreeNode* root) {
	if (root == NULL) {
	    return -1;
	}
	return 1 + max(height(root->left), height(root->right));
    }
};
