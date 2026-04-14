// For an anagram to exist, they have to have the same letters with the same frequency.
// If both words are not the same size, not an anagram.
// Check the character counts of both words and make sure they match.
class Solution {
public:
    bool isAnagram(string s, string t) {
		if(s.size() != t.size())
			return false;

		unordered_map<char, int> count;
		for (int i=0; i<s.size(); i++) {
			if (!count.count(s[i]))
				count[s[i]] = 0;
			count[s[i]]++;
		}

		for (int i=0; i<t.size(); i++) {
			if (!count.count(t[i]))
				return false;
			if (count[t[i]] <= 0)
				return false;
			count[t[i]]--;
		}
		return true;
    }
};
