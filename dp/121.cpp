// We want to buy low and sell high. To do this:
// Iterate over the array left to right. Record the minimum number so far.
// If we find a number that is less than the current minimum, update minSoFar.
// This is because it's better to buy at the current minimum than at a previous one.
// Otherwise, update the maxSoFar to be the max of itself and the current price -
// minSoFar.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSoFar = 0;
        int minSoFar = prices[0];

        for (int p : prices) {
            if (p < minSoFar) 
                minSoFar = p;
            
            maxSoFar = max(maxSoFar, p-minSoFar);
        }
        return maxSoFar;
    }
};
