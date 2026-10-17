// IDEA: keep track of the first instance of 0, 1, and 2.
// 0 has to go before the first instance of 1 and 2
// 1 has to go before the first instance of 2
// 2 can just stay there
//
// If there's a condition where this is not true, swap the elements and update the indexes
// This swap might have to be done multiple times on the same index
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int l = 0, r = nums.size()-1;
		vector<int> first = {-1, -1, -1};
		for (int  i=0; i<nums.size(); i++) {
			if (first[nums[i]] == -1)
				first[nums[i]] = i;
			while ((nums[i] < 2 && first[nums[i]+1] != -1) || (nums[i] < 1 && first[nums[i]+2] != -1)) {
				for (int x = nums[i]+1; x < 3; x++) {
					if (first[x] == -1)
						continue;
					int tmp = nums[i];
					nums[i] = x;
					nums[first[x]] = tmp;
					// If there is no first for i, then the position after swap
					// becomes the first. Otherwise the first should be right because
					// we are inserting just before the first instance of the next number
					// (which should be after the first instance of the cur number)
					if (first[tmp] == i)
						first[tmp] = first[x];

					// For the number that we swapped to the right, if there is another instance of itself next
					// to it, that becomes the first. Otherwise, the first is its new position
					if (nums[first[x]+1] == x)
						first[x]++;
					else 
						first[x] = i;
					break;
				}
			}
		}
    }
};
