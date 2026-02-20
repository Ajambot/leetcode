class Solution {
public:
    int vecSum(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }

    // Vector can only be paritioned when sum of vector is even
    // Find permutation of elements that add up to (sum of vector)/2
    // Then the problem becomes like 322. coin change except elements
    // cannot be repeated. For this, use this trick: traverse from 
    // (sum of vector)/2 to 0 (backwards) so that you don't add an element
    // to itself. Order of the numbers doesn't matter since we are doing
    // addition.
    bool canPartition(vector<int>& nums) {
        int sum = vecSum(nums);
        if (sum%2 != 0) {
            return false;
        }

        sum /= 2;

        vector<bool> possible(sum, false);
        possible[0] = true;

        for (int num: nums) {
            for (int i=sum; i >= 0; i--) {
                if (possible[i] && i+num <= sum) {
                    if (i+num == sum)
                        return true;
                    possible[i+num] = true;
                }
            }
        }
        return false;
    }
};
