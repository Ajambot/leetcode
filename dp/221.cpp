class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i=0; i<matrix.size(); i++) {
            for (int o=0; o<matrix[0].size(); o++) {
                if (!i || !o || matrix[i][o] == '0') {
                    dp[i][o] = matrix[i][o]-'0';
                } else {
                    int l = dp[i-1][o];
                    int u = dp[i][o-1];
                    int lu = dp[i-1][o-1];

                    dp[i][o] = min({l, u, lu})+1;
                }
                maxArea = max(maxArea, dp[i][o]*dp[i][o]);
            }
        }
        return maxArea;
    }
};
