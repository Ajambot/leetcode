// 2 core ideas in this solution:
// 1. It doesn't matter how we store the information, just that we retrieve it in the correct order
// 2. The order in which retrieve elements in a stack is the reverse of what we do in a queue
//
// With this, we can design the following solution: have a stack to insert the elements and a stack
// to consume (pop or peek) the elements. When we need to consume an element, we have to reverse the
// order of the elements in the stack. We do this by emptying the insert stack into the consume stack.
//
// Optimization: we don't need to reverse the order again to be able to insert. We can just keep
// consuming from the consume stack until it's empty and then reverse the insert stack when we need to.
	
class MyQueue {
public:
	stack<int> insertSt, consumeSt;
	MyQueue() {
	}

	void push(int x) {
		insertSt.push(x);
	}

	int pop() {
		if (consumeSt.empty()) {
			reverseStack();
		}
		int temp = consumeSt.top();
		consumeSt.pop();
		return temp;
	}

	int peek() {
		if (consumeSt.empty()) {
			reverseStack();
		}
		int temp = consumeSt.top();
		return temp;
	}

	bool empty() {
		return insertSt.empty() && consumeSt.empty();
	}
private:
	void reverseStack() {
		while (!insertSt.empty()) {
			consumeSt.push(insertSt.top());
			insertSt.pop();
		}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
