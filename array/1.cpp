// To find if there are two numbers that add up to target we do the following:
//
// Iterate over every number in order:
//	if we have seen (target - curNumber) in the array before,
//	then curNumber, target - curNumber is a pair that adds up to target
//
//	otherwise, remember that we have seen the current number and which 
//	index it was in. This is helpful for future checks
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> dict;

		for (int i=0; i<nums.size(); i++) {
			if (dict.count(target-nums[i])) {
				return {dict[target-nums[i]], i};
			}
			dict[nums[i]] = i;
		}
		return {-1, -1};
    }
};
