class Solution {
public:
	// IDEA: sorting the vectors makes this problem so much easier.
	// By sorting, you have assurance that they are going to be in a continuous run where you can
	// go down the number line merging them.
	//
	// There is no overlap if x1 <= y1 < x2 <= y2, there is overlap otherwise.
	//
	// If there is overlap, merge but don't insert (we could have consecutive overlapping intervals, so
	// keep merging them and insert only when there is no more overlaps). Once there is no overlaps, insert
	// the current interval
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> merged;
		sort(intervals.begin(), intervals.end());

		vector<int> curInterval = intervals[0];
		for (int i=1; i<intervals.size(); i++) {
			if (isOverlap(curInterval, intervals[i])) {
				curInterval[1] = max(curInterval[1], intervals[i][1]);
			} else {
				merged.push_back(curInterval);
				curInterval = intervals[i];
			}
		}
		merged.push_back(curInterval);
		return merged;
	}

	bool isOverlap(vector<int> i1, vector<int> i2) {
		return i2[0] <= i1[1];
	}
};
