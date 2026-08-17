class Solution {
public:
    int countValidPrefixes(string s) {
		int ans = 0;
		int zero = 0, one = 0;
		for (char c : s) {
			if (c == '0') {
				zero++;
			} else {
				one++;
			}
			if (abs(zero-one) <= 1) {
				cout << zero << " " << one << endl;
				ans++;  
			} 
		}
		return ans;
    }
};
