class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> negsAhead(nums.size());

        for (int i=nums.size()-1, curNeg=0; i>=0; i--) {
            negsAhead[i] = curNeg;
            if (nums[i] == 0) {
                curNeg = 0;
            }
            else if (nums[i] < 0) {
                curNeg += 1;
            }
        }

        int maxProd = nums[0];
        int curProd=-11, secBest=-11;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                maxProd = max(maxProd, nums[i]);
                curProd = -11;
                secBest = -11;
                continue;
            }
            if (curProd == -11) {
                curProd = nums[i];
                maxProd = max(maxProd, curProd);
                continue;
            }
            curProd *= nums[i];
            maxProd = max(maxProd, curProd);
            if (secBest == -11) {
                if (curProd > 0 && negsAhead[i]%2 != 0 && nums[i] < 0) {
                    secBest = nums[i];
                    maxProd = max(maxProd, secBest);
                }
                else if (curProd < 0 && negsAhead[i]%2 == 0 && nums[i] > 0) {
                    secBest = nums[i];
                    maxProd = max(maxProd, secBest);
                }
                continue;
            } else {
                secBest *= nums[i];
                maxProd = max(maxProd, secBest);
            }
        }
        return maxProd;
    }
};
