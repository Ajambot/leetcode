// IDEA: we're trying to deduplicate records. We can use DSU to make a graph
// where all the records that are linked are connected. And at the end we iterate
// over all emails, link them to their canonical record, and create the answer vector
class DSU {
public:
	vector<int> parent; // canonical record
	vector<int> size; // size of records in the connected graph
	DSU (vector<vector<string>>& accounts) {
		parent = vector<int>(accounts.size());
		size = vector<int>(accounts.size(), 1);
		for (int i=0; i<parent.size(); i++) {
			parent[i] = i;
		}
	}

	int findParent(int idx) {
		if (parent[idx] == idx)
			return idx;
		// shorten the graph to improve complexity
		return parent[idx] = findParent(parent[idx]);
	}

	// always merge the parents and merge the smallest to the biggest.
	// This reduces complexity
	void merge (int idx1, int idx2) {
		idx1 = findParent(idx1);
		idx2 = findParent(idx2);
		if (idx1 == idx2)
			return;
		if (size[idx1] > size[idx2]) {
			parent[idx2] = idx1;
			size[idx1] = size[idx1] + size[idx2];
		} else {
			parent[idx1] = idx2;
			size[idx2] = size[idx1] + size[idx2];
		}
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		DSU dsu = DSU(accounts);
		unordered_map<string, int> emailMap;
		for (int i=0; i<accounts.size(); i++) {
			for (int o=1; o<accounts[i].size(); o++) {
				// if we have seen this email before, link both records
				// otherwise link this email to this record
				if (emailMap.count(accounts[i][o])) {
					dsu.merge(i, emailMap[accounts[i][o]]);
				} else {
					emailMap[accounts[i][o]] = i;
				}
			}
		}

		vector<vector<string>> ans;
		unordered_map<int, vector<string>> intAns;

		// map each canonical record to all its emails
		for (const auto& [email, record]: emailMap) {
			int par = dsu.findParent(record);
			if (intAns.count(par)) {
				intAns[par].push_back(email);
			} else {
				intAns[par] = {email};
			}
		}

		// map the canonical records to their names
		for (const auto& [record, emails]: intAns) {
			vector<string> ansVec = emails;
			ansVec.insert(ansVec.begin(), accounts[record][0]);
			ans.push_back(ansVec);
		}

		// sort the emails as required by the answer
		for (int i=0; i<ans.size(); i++) {
			sort(ans[i].begin()+1, ans[i].end());
		}
		return ans;
    }
};
