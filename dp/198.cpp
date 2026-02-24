class Solution {
public:
    int rob(vector<int>& nums) {
        // prev1 = max steal up to house (i-1)th without stealing from house (i-1)th
        // prev2 = max steal up to house (i-1)th stealing from house (i-1)th
        // cur1 = max steal up to the current house without stealing from current house
        // cur2 = max steal up to the current house stealing from current house
        int prev1 = 0, prev2 = 0, cur1 = 0, cur2 = 0;
        
        for (int i=0; i<nums.size(); i++) {
            // if you don't steal from current house, the current max is the max 
            // up to the previous house
            cur1 = i>=1? max(prev1, prev2): 0; 

            // if you steal from the current house, the current max is the max possible
            // by not stealing from the previous house
            cur2 = i>=1? prev1+nums[i]: nums[i];

            prev1 = cur1;
            prev2 = cur2;
        }

        return max(cur1, cur2);
    }
};
