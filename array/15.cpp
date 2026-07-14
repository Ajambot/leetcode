// IDEA: similar to two sum, we store the elements we've seen so far, however
// this time we check pairs of numbers and try to find their complement in the
// seen set. To keep only unique solutions, we use a set and we sort every triplet
// before putting them in our solution set.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> solSt;
		set<int> seen;
		seen.insert(nums[0]);
		for (int i=1; i<nums.size(); i++) {
			for (int o=i+1; o<nums.size(); o++) {
				int complement = 0-nums[i]-nums[o];
				if (seen.count(complement) != 0) {
					vector<int> validSolution = { nums[i], nums[o], complement };
					sort(validSolution.begin(), validSolution.end());
					solSt.insert(validSolution);
				}
			}
			seen.insert(nums[i]);
		}
		return vector<vector<int>>(solSt.begin(), solSt.end());
    }
};
