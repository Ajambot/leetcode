class Solution {
public:
    int minOperations(string s) {
	int minCost = INT_MAX;
	for (int i=0; i<s.length(); i++) {
	    minCost = min(minCost, costOfTurningPalindrome(s) + i);
	    s = s.substr(1) + s[0];
	}
	return minCost;
    }

    int costOfTurningPalindrome(string s) {
	int cost = 0;
	int l = 0, r = s.length()-1;
	while (l < r) {
	    int a = s[l] - 'a', b = s[r] - 'a';
	    cost += min(((b-a) + 26) % 26, ((a-b)+26)%26);
	    l++;
	    r--;
	}
	return cost;
    }
};
