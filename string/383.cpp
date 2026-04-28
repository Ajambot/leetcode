// Similar to 242. Valid anagram, we count the letters in ransomNote and magazine.
// magazine has to be a superset of ransomNote. In valid anagram, we had to check
// that both string were the same length, but in this problem, magazine can
// have more letters. 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		if (magazine.length() < ransomNote.length())
			return false;
		unordered_map<char, int> count;
		for (char c : magazine) {
			if (!count.count(c)) {
				count[c] = 1;
			} else {
				count[c]++;
			}
		}

		for (char c : ransomNote) {
			if (!count.count(c)) {
				return false;
			}
			if (count[c] <= 0) {
				return false;
			}

			count[c]--;
		}
		return true;
    }
};
