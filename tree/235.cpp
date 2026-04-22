/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Consider Path(p) to be a list of nodes containing the path to get from
    // the root to node p. The lowest common ancestor between two nodes p and q
    // is the lowest node in the tree that is both in Path(p) and Path(q). To 
    // find this, traverse the tree from the root looking for both p and q 
    // simultaneously. The moment you have to take a different path to get to
    // p and q, or the moment you find p or q, that is the lowest common ancestor.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* lca = root;
	while (true) {
	    if (lca == p || lca == q)
		return lca;
	    if (p->val < lca->val && q->val < lca->val) {
		lca = lca->left;
	    } else if (p->val > lca->val && q->val > lca->val) {
		lca = lca->right;
	    } else {
		return lca;
	    }
	}
    }
};
