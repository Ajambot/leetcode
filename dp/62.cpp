class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int o=0; o<n; o++) {
                if (i > 0) {
                    grid[i][o] += grid[i-1][o];
                }
                if (o > 0) {
                    grid[i][o] += grid[i][o-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
