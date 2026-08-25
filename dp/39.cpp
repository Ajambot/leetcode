// IDEA: This is a backtracking problem. We have to find all possible ways to reach target. 
// Below are 2 ways to solve the problem. The first is a BFS and the second is a DFS
// DFS is always better for backtracking problems because we don't have to store all intermediate
// solutions at once. We can use one single array to store the intermediate solution and then reuse it.
//
// Our subproblems for this backtracking are all of the amounts between 0 and target. We use those intermediate
// solutions to see which branches reach our target. Our base case is amount 0, which we can always get by taking
// no elements from candidates.
class Solution {
public:
    // BFS Solution
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<set<vector<int>>> mem = vector<set<vector<int>>>(41, set<vector<int>>());
        mem[0].insert(vector<int>(candidates.size(), 0));

        for (int i=0; i<=target; i++) {
            for (int j=0; j<candidates.size(); j++) {
                // Don't keep exploring branches that are above target. Useless
                if (i + candidates[j] > target)
                    continue;
                for (const auto& freq : mem[i]) {
                    vector<int> cur = freq; // this is not efficient because we have to copy the freq array for every intermediate solution
                    cur[j]++;
                    mem[i+candidates[j]].insert(cur);
                }
            }
        }
        vector<vector<int>> ans;
        // Because we are deduplicating the solutions by keeping a frequency vector, we have 
        // to compute the actual solution vectors they ask for from the frequency vectors
        for (const auto& freq : mem[target]) {
            vector<int> cur;
            for (int i=0; i<freq.size(); i++) {
                for (int o=0; o<freq[i]; o++) {
                    cur.push_back(candidates[i]);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }


    // DFS Solution
    vector<vector<int>> solution;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp = vector<int>();
        dfs(candidates, 0, target, tmp);
        return solution;
    }

    // we try to insert the cur element as much as we can to explore that branch, then
    // we move over to branches with the next candidate
    void dfs(vector<int>& candidates, int cur, int target, vector<int>& path) {
        if (target == 0) {
            solution.push_back(path);
            return;
        }
        if (target < 0 || cur >= candidates.size())
            return;
        path.push_back(candidates[cur]);
        // explore current branch
        dfs(candidates, cur, target-candidates[cur], path);
        // backtracking step
        path.pop_back();
        // check next branch
        dfs(candidates, cur+1, target, path);
    }
};
