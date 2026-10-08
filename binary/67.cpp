// IDEA: Implement simple binary addition algorithm keeping track of carry
class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() < b.length()) {
			a.insert(0, b.length()-a.length(), '0');
		}
		else if (b.length() < a.length()) {
			b.insert(0, a.length()-b.length(), '0');
		}

		int carry = 0;
		string ans = "";

		for (int i=a.length()-1; i>=0; i--) {
			int aInt = a[i] - '0';
			int bInt = b[i] - '0';
			int sum = aInt + bInt + carry;
			if (sum == 0) {
				ans = "0" + ans;
				carry = 0;
			} else if (sum == 1) {
				ans = "1" + ans;
				carry = 0;
			} else {
				if (sum == 2) {
					ans = "0" + ans;
				} else {
					ans = "1" + ans;
				}
				carry = 1;
			}
			cout << sum << " " << ans << endl;
		}
		if (carry)
			ans = "1" + ans;
		return ans;
	}
};
