/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// IDEA: Serialize and Deserialize the binary tree as a DFS traversal.
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
	if (!root) {
	    return "n ";
	}
	return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right) + " ";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
	int curIdx = 0;
	string w = parseWord(data);
	if (w == "n")
	    return NULL;
	TreeNode* root = new TreeNode(stoi(w));
	root->left = deserialize(data);
	root->right = deserialize(data);
	return root;
    }

    // The parseWord function consumes characters from the data
    // string so we are not parsing the same word over and over,
    // and also we can use the same string across recursive calls.
    string parseWord(string &data) {
	string cur = "";
	int i=0;
	while (i < data.length() && data[i] != ' ') {
	    cur += data[i];
	    i++;
	}

	while (data[i] == ' ')
	    i++;
	data = data.substr(i);
	return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
