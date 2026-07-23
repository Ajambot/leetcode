class Node {
public:
    // end represents if we have inserted a word in the trie that ends in this exact letter
    // end will be false when we have inserted a word that contains the current prefix
    // end will be true when we have inserted a word that is exactly the current prefix
    bool end; 
    unordered_map<char, Node*> children;

    Node() {
	end = false;
	children = unordered_map<char, Node*>();
    }
};

class Trie {
public:
    Node* root;
    Trie() {
	root = new Node();
    }

    // walk down the tree and create new nodes for new prefixes if needed
    void insert(string word) {
	Node* cur = this->root;
	for (char c : word) {
	    // Check if the current letter is an existing prefix before creating a new node
	    if (cur->children.count(c) == 0)
		cur->children[c] = new Node();
	    cur = cur->children[c];
	}
	cur->end = true; // mark the current word as existing in the trie
    }

    bool search(string word) {
	Node* cur = this->root;
	for (char c : word) {
	    // if the current prefix is not on our trie, then the word is not on our trie
	    if (cur->children.count(c) == 0) {
		return false;
	    }
	    cur = cur->children[c];
	}
	// only return true on exact matches
	return cur->end;
    }

    bool startsWith(string prefix) {
	Node* cur = this->root;
	for (char c : prefix) {
	    if (cur->children.count(c) == 0) {
		return false;
	    }
	    cur = cur->children[c];
	}
	// prefix exists but is not necessarily a word in the trie
	return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
