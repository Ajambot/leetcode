// IDEA: Since Reverse Polish Notation takes the 2 most recent operands (be it numbers or expressions),
// we will use a stack. This is because stacks give us the most recently added elements first, which
// matches our problem.
//
// We will add operands to the stack whenever we see them. If we see an operator, we pick the two top elements
// of the stack and do the operation on them. Then we put the result back into the stack. The solution will be the
// only element left in the stack at the end.
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<string> st;
		for (string token : tokens) {
			if (
				token != "+" &&
				token != "*" &&
				token != "-" &&
				token != "/"
			) {
				st.push(token);
			} else {
				int r = stoi(st.top());
				st.pop();
				int l = stoi(st.top());
				st.pop();
				if (token == "+")
					st.push(to_string(l+r));
				if (token == "-")
					st.push(to_string(l-r));
				if (token == "*")
					st.push(to_string(l*r));
				if (token == "/")
					st.push(to_string(l/r));
			}
		}
		return stoi(st.top());
	}
};
