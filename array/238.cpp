// IDEA: product of array except self for i = prefix product [i] * suffix product [i]
// prefix product [i] = product of all elements before i
// suffix product [i] = product of all elements after i
//
// To save memory, instead of saving the prefix and suffix products in an array,
// we use them as we calculate them.
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int pre = 1, suff = 1;
		vector<int> output(nums.size(), 1);

		int l = 0, r = nums.size()-1;
		// O(nums.size())
		while (l < nums.size()) {
			// O(1)
			output[l] *= pre;
			output[r] *= suff;
			pre *= nums[l];
			suff *= nums[r];
			l++;
			r--;
		}
		return output;
		// O(nums.size())
	}
};
