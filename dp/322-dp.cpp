vector<int> mem(10001, INT_MAX);
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        fill(mem.begin(), mem.end(), INT_MAX);
        mem[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i-coin >= 0 && mem[i-coin] != INT_MAX) {
                    mem[i] = min(mem[i], mem[i-coin] + 1);
                }
            }
        }
        return mem[amount] == INT_MAX? -1: mem[amount];
    }
};
