// Idea: insert any non-overlapping intervals. Then, for any overlapping intervals,
// merge them with the newInterval then insert the mergedInterval.
//
// 3 cases to check for overlap:
// 1. the left end of the newInterval is inside the curInterval
// 2. the right end of the newInterval is inside the curInterval
// 3. the curInterval is entirely contained by the newInterval
//
// To find merged interval, keep the minimum end of all overlapping intervals
// and the maximum end of all overlapping intervals. The merged interval should
// be [minL, minR]
class Solution {
public:
	bool overlaps(int curL, int curR, int l, int r) {
		return (curL <= l && l <= curR) || (curL <= r && r <= curR) || (l <= curL && curR <= r);
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int l = newInterval[0], r = newInterval[1];
		vector<vector<int>> ans;

		bool hasInserted = false;
		for (auto interval : intervals) {
			int curL = interval[0], curR = interval[1];
			if (!overlaps(curL, curR, l, r)) {
				if (curL > r && !hasInserted) {
					ans.push_back({l, r});
					hasInserted = true;
				}
				ans.push_back({curL, curR});
			} else {
				l = min(l, curL);
				r = max(r, curR);
			}
		}

		if (!hasInserted) {
			ans.push_back({l, r});
		}
		return ans;
	}

};
