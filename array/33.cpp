// IDEA: Run Binary Search twice. Once, to find the beginning element of our (possibly) rotated
// array. And another time, to run actual binary search on the rotated array (of which we know the
// starting index now). We use modulo to compute the rotated index for our 2nd binary search
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1;

		while (l < r) {
			int m = (l+r)/2;
			// If our right half is sorted, then the first index has to be in our left half (cur element included)
			if (nums[m] < nums[r]) {
				r = m;
			// if our right half is not sorted, then the first index has to be in the right half (cur element not included)
			} else {
				l = m+1;
			}
		}

		return binarySearch(l, l + nums.size(), target, nums);
	}

	// rotated binary search using modulo
	int binarySearch(int l, int r, int target, vector<int>& nums) {
		int mid = (l+r)/2;
		if (l>r)
			return -1;
		if (nums[mid%nums.size()] == target)
			return mid%nums.size();
		if (nums[mid%nums.size()] < target)
			return binarySearch(mid+1, r, target, nums);
		return binarySearch(l, mid-1, target, nums);
	}
};
