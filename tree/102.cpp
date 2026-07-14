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
    // IDEA: Use BFS Level Traversal trick to know when a level ends and the next one begins.
    // Append each level one by one.
    vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	vector<vector<int>> solution;
	if (!root) return solution;
	while (!q.empty()) {
	    vector<int> curVec;
	    // BFS Level Traversal trick: Store the size of the queue
	    // at each iteration and pop exactly that amount of elements.
	    // That should be a whole level.
	    int qSize = q.size();
	    for (int i=0; i<qSize; i++) {
		TreeNode* cur = q.front();
		curVec.push_back(cur->val);
		q.pop();
		if (cur->left) q.push(cur->left);
		if (cur-> right) q.push(cur->right);
	    }
	    solution.push_back(curVec);
	}
	return solution;
    }
};
