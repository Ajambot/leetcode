/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
	val = 0;
	neighbors = vector<Node*>();
    }
    Node(int _val) {
	val = _val;
	neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
	val = _val;
	neighbors = _neighbors;
    }
};
*/

// IDEA: recursively create new nodes for the deep copy of the graph. However,
// only create nodes when they have not been created in the past. If we have already
// created the node we're trying to clone, return a reference to the previously created
// node instead of creating a new one. We check if we have already created a node by storing
// previously created nodes in an array.
Node* nodeDone[101];

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) return node;

		for (int i=0; i<=100; i++) {
			nodeDone[i] = nullptr;
		}
		Node* cur = new Node();
		return cloneRecursive(node);
	}

	Node* cloneRecursive(Node* node) {
		if (nodeDone[node->val]) {
			return nodeDone[node->val];
		}
		Node* cur = new Node(node->val);
		nodeDone[cur->val] = cur;
		for (Node* n : node->neighbors) {
			cur->neighbors.push_back(cloneRecursive(n));
		}
		return cur;
	}
};
