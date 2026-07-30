// IDEA: 2 cases. Even length palindrome, we need n/2 pairs of the same letter
// Odd lenghth palindrome, we need floor(n/2) pairs of the same letter + any single letter
//
// To find the longest palindrome, find all possible pairs of the same letter, and then if
// we have an extra single letter, add +1 to the result. 
// Length of longest palindrome = (# of pairs) * 2 + if (extra single letter) then 1 else 0
class Solution {
public:
    int longestPalindrome(string s) {
		int ans = 0;
		unordered_set<char> singles;

		// O(s.length())
		for (char c : s) {
			// O(1)
			if (singles.count(c) != 0) {
				ans += 2;
				singles.erase(c);
			} else {
				singles.insert(c);
			}
		}

		if (!singles.empty())
			ans++;
		return ans;
		// O(s.length());
    }
};
