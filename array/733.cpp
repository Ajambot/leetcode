class Solution {
public:
	// The algorithm goes as follows:
	// 1. remember the starting color of the pixel at [sr][sc]
	// 2. create a queue to store all of the elements we need to color. Put [sr][sc] there
	// 3. also create a set to store all elements we have added to the queue so we don't add the same element twice
	// Then while the queue isn't empty:
	//	- color the element at the front of the queue
	//	- add all adjacent elements that have the same as the starting color to the queue and the set
	//	- pop the element at the front of the queue
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		int st_col = image[sr][sc];
		queue<pair<int, int>> q;
		set<pair<int, int>> st;
		q.push({sr, sc});
		st.insert({sr, sc});

		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			int curR = cur.first, curC = cur.second;
			image[curR][curC] = color;

			if (curC-1 >= 0 && st.count({curR, curC-1}) == 0 && image[curR][curC-1] == st_col) {
				q.push({curR, curC-1});
				st.insert({curR, curC-1});
			}

			if (curR-1 >= 0 && st.count({curR-1, curC}) == 0 && image[curR-1][curC] == st_col) {
				q.push({curR-1, curC});
				st.insert({curR-1, curC});
			}

			if (curC+1 < image[0].size()  && st.count({curR, curC+1}) == 0 && image[curR][curC+1] == st_col) {
				q.push({curR, curC+1});
				st.insert({curR, curC+1});
			}

			if (curR+1 < image.size() && st.count({curR+1, curC}) == 0 && image[curR+1][curC] == st_col) {
				q.push({curR+1, curC});
				st.insert({curR+1, curC});
			}
		}
		return image;
	}
};
