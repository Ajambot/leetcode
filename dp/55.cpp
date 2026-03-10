class Solution {
public:
    // idea: record the minimum jump length to reach last index
    // then iterate over array from end to beginning checking if
    // the current index can jump at least the minimum jump length
    // required. If it can, instead of checking if you can jump to 
    // the end, check if you can jump to the last index that we know
    // can jump to the end (i.e. update minimum jump length to be the min to
    // reach the last successful index)
    bool canJump(vector<int>& nums) {
        int needAtLeast = 0;
        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] >= needAtLeast) {
                needAtLeast = 0;
            }
            needAtLeast++;
        }
        return needAtLeast == 1;
    }
};
