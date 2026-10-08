// IDEA: for every instance of the majority element, there
// can be a non-majority element cancelling it out. But because
// the majority element occurs more than floor(n/2) times, there
// will always be an extra one at the end.
//
// Use Moore's Voting Algorithm with a candidate for the majority element.
// When you see that same element, increase the count by 1. If you see
// a different element, reduce the count by 1. Once the count reaches 0,
// the cur element becomes the candidate and the count goes to 1.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curVal = INT_MAX;
        int curAmount = 1;
        for (auto num : nums) {
            curAmount += curVal == num? 1: -1;
            if (curAmount == 0) {
                curVal = num;
                curAmount = 1;
            }
        }
        return curVal;
    }
};
