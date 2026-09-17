/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// IDEA: a node is LCA when one of p and q is to the left and the other to the right. This is because
// we cannot go deeper in the tree without losing one of p or q by doing so.
//
// If they are both to the left, check if left subtree is LCA. Same with the right
class Solution {
public:
    map<pair<int, int>, bool> cache;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	cache.clear();
	return FindLCA(root, p, q);
    }

    TreeNode* FindLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == p || root == q) {
	    return root;
	}

	string pIn = IsInSubtree(root->left, p)? "left" : "right";
	string qIn = IsInSubtree(root->left, q)? "left" : "right";
	if ((pIn == "left" && qIn == "right") || (pIn == "right") && qIn == "left") {
	    return root;
	}
	else if (pIn == "left" && qIn == "left") {
	    return FindLCA(root->left, p, q);
	}
	else {
	    return FindLCA(root->right, p, q);
	}
    }

    // INORDER lookup of q with a cache
    bool IsInSubtree(TreeNode* root, TreeNode* q) {
	if (root == NULL) {
	    return false;
	} 
	if (cache.count({root->val, q->val}))
	    return cache[{root->val, q->val}];
	if (root == q) {
	    cache[{root->val, q->val}] = true;
	    return true;
	}
	cache[{root->val, q->val}] = IsInSubtree(root->left, q) || IsInSubtree(root->right, q);
	return cache[{root->val, q->val}];
    }
};
