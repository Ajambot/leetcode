// IDEA: Use 2 stacks. st keeps track of all elements. minSt keeps track
// of the minimum elements. To have a historical record of all min elements,
// we must also keep the 'point in time' when they were first added. Here
// we represent that as the size of st when they were added. With this second parameter,
// we can know when we need to pop from the minSt (which is when we pop the stack
// at size minSt.top().second).
class MinStack {
public:
	stack<int> st;
	stack<pair<int, int>> minSt;
	// O(1)
	MinStack() {
		st = stack<int>();
		minSt = stack<pair<int, int>>();
	}

	// O(1)
	void push(int value) {
		st.push(value);
		// if empty, add regardless
		if (minSt.empty() || value < minSt.top().first) {
			minSt.push({value, st.size()});
		}
	}

	// O(1)
	void pop() {
		if (st.top() == minSt.top().first && minSt.top().second == st.size()) {
			minSt.pop();
		}
		st.pop();
	}

	// O(1)
	int top() {
		return st.top();
	}

	// O(1)
	int getMin() {
		return minSt.top().first;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
