class Solution {
public:
    // IDEA: We do n iterations where on each iteration i we build all possible permutations
    // of length i using the permutations of length i-1 (we append each candidate to those
    // permutations as long as they are not already there)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms(1, vector<int>());
        for (int i=0; i<nums.size(); i++) {
            vector<vector<int>> newPerms;
            for (int num: nums) {
                for (vector<int> p : perms) {
                    // don't insert the same element twice
                    if (find(p.begin(), p.end(), num) != p.end())
                        continue;
                    p.push_back(num);
                    newPerms.push_back(p);
                }
            }
            perms = newPerms;
        }
        return perms;
    }
};

