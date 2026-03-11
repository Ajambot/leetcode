class Solution {
public:
    int expand(vector<vector<char>>& matrix, int i, int o, int level) {
        int maxLevel = level;
        while (true) {
            if (i+maxLevel >= matrix.size() || o+maxLevel >= matrix[0].size())
                return maxLevel;
            for (int x=0; x<=maxLevel; x++) {
                if (matrix[i+maxLevel][o+x] == '0' || matrix[i+x][o+maxLevel]=='0')
                    return maxLevel;
            }
            maxLevel++;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxArea = 0;
        for (int i=0; i<matrix.size(); i++) {
            for (int o=0; o<matrix[0].size(); o++) {
                if (matrix[i][o]-'0' != 0) {
                    if (maxArea>=(matrix.size()-i+1) * (matrix[0].size()-o+1)){
                        continue;
                    }
                    int l = i-1>=0? matrix[i-1][o]-'0': 0;
                    int u = o-1>=0? matrix[i][o-1]-'0': 0;
                    int lu = (i-1>=0 && o-1>=0)? matrix[i-1][o-1]-'0':0;
                    int curMaxLevel = max({l-1, u-1, lu-1, matrix[i][o]-'0'});
                    int actMaxLevel = expand(matrix, i, o, curMaxLevel);
                    matrix[i][o] = '0' + actMaxLevel;
                    maxArea = max(maxArea, actMaxLevel*actMaxLevel);
                }
            }
        }
        return maxArea;
    }
};
