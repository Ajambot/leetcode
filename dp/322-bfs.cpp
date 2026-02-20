class Solution {
public:
    long long coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount+1, INT_MAX);
        queue<int> q;
        mem[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int coin: coins) {
                if ((long)cur + (long)coin <= (long)amount && mem[cur+coin] > mem[cur] + 1) {
                    mem[cur+coin] = mem[cur]+1;
                    q.push(cur+coin);
                }
            }
        }
        return mem[amount] == INT_MAX? -1: mem[amount];
    }
};
