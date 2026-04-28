// We need to use BFS to find the shortest distance between every number and the closest 0.
// We start outward with all 0s and initialize their distance to 0 and add them to the queue.
// For every neighbor that we haven't visited, the distance will be the curDist + 1. We update
// said distance and then visit unvisited neighbors. BFS traversal order guarantees minimum distance.
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
		for (int i=0; i<n; i++) {
			for (int o=0; o<m; o++) {
				if (mat[i][o] == 0) {
					ans[i][o] = 0;
					q.push({i, o});
				}
			}
		}

		vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		while (!q.empty()) {
			auto [curX, curY] = q.front();
			q.pop();

			for (auto [dirX, dirY] : dirs) {
				int newX = curX + dirX, newY = curY + dirY;
				if (newX >= 0 && newX < n && newY >= 0 && newY < m && ans[newX][newY] == INT_MAX) {
					ans[newX][newY] = ans[curX][curY] + 1;
					q.push({newX, newY});
				}
			}
		}
		return ans;
	}
};
