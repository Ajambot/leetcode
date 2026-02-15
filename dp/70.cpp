#include <bits/stdc++.h>

// Ways to get to stair n = (ways to get to stair n-1) + (ways to get to stair n-2)
// since we can only climb 1 or 2 stairs. This is basically fibonacci.
class Solution {
public:
    int climbStairs(int n) {
        if (n <=1) return 1;
        int l = 1, r = 1;
        n--;
        while (n>0) {
            int temp = r;
            r = l+r;
            l = temp;
            n--;
        }
        return r;
    }
};
