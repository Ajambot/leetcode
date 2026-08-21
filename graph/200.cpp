// IDEA: Run DFS on every unvisited cell. DFS will explore the whole island. Every time we find an unvisited cell,
// that means this is a disconnected piece of land
class Solution {
public:
	vector<vector<bool>> visited;
	int numIslands(vector<vector<char>>& grid) {
		visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
		int numIslands = 0;
		for (int i=0; i<grid.size(); i++) {
			for (int o=0; o<grid[0].size(); o++) {
				if (grid[i][o] == '1' && !visited[i][o]){
					numIslands++; // disconnected land. Increase islands
					dfs(grid, i, o);
				}
			}
		}
		return numIslands;
	}

	void dfs(vector<vector<char>>& grid, int x, int y) {
		visited[x][y] = true;
		if (x+1 < grid.size() && !visited[x+1][y] && grid[x+1][y] == '1')
			dfs(grid, x+1, y);
		if (x-1 >= 0 && !visited[x-1][y] && grid[x-1][y] == '1')
			dfs(grid, x-1, y);
		if (y+1 < grid[0].size() && !visited[x][y+1] && grid[x][y+1] =='1')
			dfs(grid, x, y+1);
		if (y-1 >= 0 && !visited[x][y-1] && grid[x][y-1] == '1')
			dfs(grid, x, y-1);
	}
};
