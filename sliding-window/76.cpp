// IDEA: Use the frequencies of the characters in t to keep track of the letters we 
// used/are missing from t in the current window
//
// Add elements to our current window and keep track of the first char (i.e. the anchor).
//
// If the frequency of the anchor is < 0 (i.e. we have more letters of it than we need),
// then we can get rid of it. We keep doing this until the anchor frequency is >= 0
//
// When we find a solution, compare it against the min to see if it's better
class Solution {
public:
	string minWindow(string s, string t) {
		// edge case. t cannot fit in s
		if (t.length() > s.length())
			return "";

		vector<int> freqs(58, 0);

		// create freqs vector
		for (char c: t) {
			freqs[c-'A']++;
		}

		string minAns = "";
		
		// curS keep strack of our current window
		queue<pair<char, int>> curS;
		for (int i=0; i<s.length(); i++) {
			curS.push({s[i], i});
			freqs[s[i]-'A']--;

			// Flush anchors until our anchor is not extra
			while (!curS.empty() && freqs[curS.front().first-'A'] < 0) {
				freqs[curS.front().first-'A']++;
				curS.pop();
			}

			if (checkIfDone(freqs)) {
				string cur = s.substr(curS.front().second, i-curS.front().second+1);
				// compare to global minimum
				minAns = (minAns == "" || (minAns.length() >= cur.length()))? cur : minAns;
			}
		}
		return minAns;
	}

	bool checkIfDone(vector<int>& freqs) {
		for (int freq: freqs) {
			if (freq > 0) return false;
		}
		return true;
	}
};
