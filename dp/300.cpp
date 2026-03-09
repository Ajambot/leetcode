class Solution {
public:
    // longest vector stores longest increasing subsequence using number at index i
    // calculate longest[i] by checking all o < i. If nums[o] < nums[i], that means
    // we can have a possible subsequence of length longest[o] + 1. Keep only the max
    // subsequence amongst all o < i and do this for all indexes.
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longest(nums.size(), 1);
        
        for (int i=0; i<nums.size(); i++) {
            int maxLen = 0;
            for(int o=0; o<i; o++) {
                if (nums[o]<nums[i]) {
                    maxLen = max(maxLen, longest[o]);
                }
            }
            longest[i] = maxLen+1;
        }

        return *max_element(longest.begin(), longest.end());
    }
}; 
