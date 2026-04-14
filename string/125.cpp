// Two pointers approach:
// Have a pointer at the beginning of the string and one at the end.
// Both pointers move inwards. If the character at any pointer is 
// not alphanumeric, skip that character. Then compare if the characters
// (lowercased) at both pointers are the same, if not the word is not a palindrome.
// One the left and right pointers overlap or pass each other, we're done
// checking. return true.
class Solution {
public:
	bool isPalindrome(string s) {
		int l = 0, r = s.length()-1;

		while (l < r) {
			while (!isalnum(s[l])) {
				l++;
				if (l >= s.length())
					return true;
			}
			while (!isalnum(s[r])){
				r--;
				if (l >= s.length())
					return true;
			}

			if (tolower(s[l]) != tolower(s[r])) {
				return false;
			}
			l++;
			r--;
		}
		return true;
	}
};
