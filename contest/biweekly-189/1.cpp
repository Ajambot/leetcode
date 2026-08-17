class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
		int curFloor = 0;
		int ans = 0;
		for (int request : requests) {
			ans += abs(curFloor-request);
			curFloor = request;
		}
		return ans;
    }
};
