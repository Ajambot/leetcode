/*
 * Similar to coin change. We count the amount of ways we can reach integer amounts up to
 * the target. Then starting with 0 (which we can always reach in 1 way [by not picking
 * any coin]), we add the amount of ways we can get to the current amount to all of the
 * amounts that we can reach by adding one of the coins to the current amount. 
 * Then we return the amount of ways we can reach the target.
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> ans(target+1, 0);
        ans[0] = 1;

        for (int i=0; i<target; i++) {
            if (ans[i] != 0) {
                for (int coin: nums) {
                    if ((long long)i+coin <= (long long)target) {
                        // we mod the answer because the problem
                        // assures us the final answer fits in a 32 bit integer
                        // some intermediate answers that don't lead to the final
                        // answer exceed this amount.
                        ans[i+coin] += (long long)ans[i]%INT_MAX;
                    }
                }
            }
        }
        return ans[target];
    }
};
