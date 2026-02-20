class Solution {
public:
	// Answer is the amount of permutations with repetition of m spaces down
	// and n spaces right. This is just a smart way of calculating that without
	// overflow.
	int uniquePaths(int m, int n) {
		long long x = max(m, n)-1;
		long long y = min(m, n)-1;

		long long ans = 1;
		for (long long i = x+1, j = 1; i <= x+y; i++, j++) {
			ans *= i;
			ans /= j;
		}
		return (int)ans;
	}
};
