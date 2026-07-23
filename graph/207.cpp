// IDEA: we can express this as a graph problem. Every node is a course and every edge (u,v) represents a prerequisite
// where course u is a prerequisite for course v. Our task is to find if there are any cycles in this graph. If so,
// it is not possible to complete all courses.
//
// To detect a cycle we run the DFS algorithm while also noting the active path in our search. If we find a node and 
// it's also in our active path, that means there is a cycle in our active path.
//
// Keep also a seen set so we don't explore nodes we've explored fully in the past.
set<int> seen;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		seen.clear();
		set<int> path;
		unordered_map<int, vector<int>> adjList;
		// Convert list of edges to adjacency list O(E)
		for (vector<int> preReq : prerequisites) {
			if (adjList.count(preReq[0]) == 0) {
				adjList[preReq[0]] = *(new vector<int>);
			}
			adjList[preReq[0]].push_back(preReq[1]);
		}

		// Run DFS on every node we have not previously explored O(V + E)
		for (const auto& [u , v] : adjList) {
			if ((seen.count(u) == 0 && !dfs(adjList, u, path)))
				return false;
		}
		return true;
	}

	// VERY IMPORTANT: adjList and path should be passed as reference, not value.
	// Otherwise we are making a copy of both every time we call dfs. This is very inefficient
	// and can make the solution TLE.
	bool dfs(unordered_map<int, vector<int>>& adjList, int curNode, set<int>& path) {
		seen.insert(curNode);
		path.insert(curNode);

		for (int outNode : adjList[curNode]) {
			if (path.count(outNode) || (seen.count(outNode) == 0 && !dfs(adjList, outNode, path)))
				return false;
		}
		path.erase(curNode); // backtracking step
		return true;
	}
};

