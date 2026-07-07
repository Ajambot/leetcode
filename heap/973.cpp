// Find K closest points to origin:
// IDEA - put the distances between point and origin in a min_heap
// Then, at the end, pop k elements from the heap and that's our answer
// We need to put the index of the point in the heap so we can retrieve the points after
// getting the distances from the heap
class Solution {
public:
	int getDistanceToOrigin(vector<int> p) {
		return (p[0])*(p[0]) + (p[1])*(p[1]);
	}

	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<pair<int, int>> hp;

		for (int i=0; i<points.size(); i++) {
			vector<int> point = points[i];
			hp.push({-getDistanceToOrigin(point), i}); // priority q is max heap by default. Insert negative elements to make minHeap
		}

		vector<vector<int>> ans;
		for (int i=0; i<k; i++) {
			auto [dist, idx] = hp.top();
			ans.push_back(points[idx]);
			hp.pop();
		}
		return ans;
	}
};
