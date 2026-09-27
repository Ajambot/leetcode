// IDEA: Use a monotonically decreasing stack to keep track of the heights
// that we have traversed. We consume the top of the stack once we find a
// height that is not decreasing. If we find a height that is not decreasing
// all of the heights to the left of it that are less than it, will not matter
// in the future (the current wall will cover them).
//
// When we consume from the stack, we check if we trapped any water between the cur
// wall and any previous walls and we add that to the total water.
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> st;
		int water = 0;

		for (int i=0; i<height.size(); i++) {
			// always push if stack empty
			if (st.empty()) {
				st.push(i);
				continue;
			}
			// keep the rightmost position always if the h is same, otherwise
			// you miscalculate the area
			if (height[i] == height[st.top()]) {
				st.pop();
				st.push(i);
				continue;
			} 
			
			// consume from stack
			if (height[i] > height[st.top()]) {
				// r is right wall, b is bottom, l is left wall
				// we trap water in between these walls
				int r = i;
				int b = st.top();
				st.pop();
				while (!st.empty()) {
					int l = st.top();
					int w = r - l - 1;
					int h = min(height[r], height[l]) - height[b];
					int a = w * h;
					water += a;
					// If the current wall is smaller than left, we do not consume it, just 
					// add the captured water and exit
					if (height[l] > height[r])
						break;

					// pop the left wall and left becomes our new bottom
					st.pop();
					b = l;
				}
			}

			// at the end always push the current wall.
			st.push(i);
		}
		return water;
	}
};
