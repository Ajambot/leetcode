// IDEA: BFS helps us find the shortest path from rotten orange to all adjacent oranges.
// Therefore, we can find the minimum time across all oranges.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> q;
		for (int i=0; i<grid.size(); i++) {
			for (int o=0; o<grid[0].size(); o++) {
				if (grid[i][o] == 2) {
					// add rotten oranges to q to start
					q.push({i, o});
				}
			}
		}

		int numSeconds = 0;
		while (!q.empty()) {
			int qSize = q.size();
			// BFS trick to count distance (time) from beginning points
			for (; qSize>0; qSize--) {
				auto [x, y] = q.front();
				q.pop();
				if (x+1 < grid.size() && grid[x+1][y] == 1) {
					q.push({x+1, y});
					grid[x+1][y] = 2; // mark as rotten before visiting so we don't add the same orange twice
				}
				if (x-1 >= 0 && grid[x-1][y] == 1) {
					q.push({x-1, y});
					grid[x-1][y] = 2;
				}
				if (y+1 < grid[0].size() && grid[x][y+1] ==1) {
					q.push({x, y+1});
					grid[x][y+1] = 2;
				}
				if (y-1 >= 0 && grid[x][y-1] == 1) {
					q.push({x, y-1});
					grid[x][y-1] = 2;
				}
			}
			numSeconds++;
		}

		int numOranges = 0;
		for (int i=0; i<grid.size(); i++) {
			for (int o=0; o<grid[0].size(); o++) {
				if (grid[i][o] == 2)
					numOranges++;
				// If there's any non rotten oranges, return -1 because we can't reach them
				if (grid[i][o] == 1) {
					return -1;
					numOranges++;
				}
			}
		}
		if (!numOranges) return 0; // If there's no oranges at all, then it takes 0 minutes to infect all fresh oranges
		return numSeconds-1;
    }
};
