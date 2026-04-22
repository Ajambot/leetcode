class Solution {
public:
	// Binary search: The idea here is that since we have a sorted list
	// we can discard big chunks of the list by doing a smart search. 
	// The algorithm works as follows:
	// 1. keep track of l and r which delimit the left and right bounds
	// of the section of the list we still have to search through
	// 2. get the middle element of the section delimited by l and r
	// 3. if this middle element is less than the item we are looking for,
	// discard all elements in the list that are before it, since they all will
	// also be less than the element we are looking for.
	// 4. if it's greater than the target, discard all elements to the right
	// 5. otherwise, we found the target, so return the index
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1;

		while (l<=r) {
			int m = (l+r)/2;
			if (target < nums[m]) {
				r = m-1;
			} else if (target > nums[m]) {
				l = m+1;
			} else {
				return m;
			}
		}

		return -1;
	}
};
