#include <bits/stdc++.h>

class Solution {
public:
    // Kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, cursum=0;

        for (int i: nums) {
            if (cursum+i < i) {
                cursum = i;
            }
            else {
                cursum += i;
            }
            maxSum = max(maxSum, cursum);
        }

        return maxSum;
    }
};
