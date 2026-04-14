// Put any open brackets in a stack. If we see a closing bracket,
// check if the last open bracket we saw was a matching one. If not,
// the string is not valid. If there are any opening brackets left in 
// the stack, that means we had an opening bracket that wasn't closed.
// Therefore, the string would not be valid.
class Solution {
public:
    bool isValid(string s) {
		unordered_map<char, char> ref;
		ref[')'] = '(';
		ref[']'] = '[';
		ref['}'] = '{';

		stack<char> st;
		for (int i=0; i<s.length(); i++) {
			if (ref.count(s[i]) == 0) {
				st.push(s[i]);
			} else {
				if (st.size() == 0) {
					return false;
				}

				if (!(st.top() == ref[s[i]])) {
					return false;
				}

				st.pop();
			}
		}

		return st.empty();
    }
};
