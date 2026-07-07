// Length of Longest Substring without repeating characters:
// IDEA - Keep a window with edges l and r. Make sure our window is always
// a solution for the problem. Maintain a maxSolution so far that we update
// every time we find a new possible solution to the problem
//
// By solution, I mean a substring with no repeated characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.length()==0) return 0;
		int l = 0, r = 0;
		int maxSolution = 1;
		unordered_map<char, int> hmap;
		while (r < s.length()) {
			if (hmap.count(s[r])==0)
				hmap[s[r]] = 0;
			
			// Here we guarantee that our window has a valid solution
			// by removing characters from the window until the duplicate
			// is eliminated
			while (hmap[s[r]] != 0){ 
				hmap[s[l]]--;
				l++;
			}

			hmap[s[r]]++;
			maxSolution = max(maxSolution, r-l+1);
			r++;
		}
		return maxSolution;
    }
};
