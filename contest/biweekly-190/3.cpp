class Solution {
public:
	// IDEA: instead of merging letters one by one, we find the max letter that we can build with 
	// the As we have in front of us. We can build the ith letter of the alphabet if we have 2^i 
	// As in front of us. We always merge as much as we can. 
	vector<string> largestString(vector<int>& nums) {
		string abc = "abcdefghijklmnopqrstuvwxyz";
		int maxP = 25; // we can't merge zz, so the limit is 2^25 As

		vector<string> ans;
		for (int i=0; i<nums.size(); i++) {
			int curIdx = 0;

			string curans = "";
			while (curIdx < nums[i]) {
				int maxIdx = 0;
				// Find the max letter we can create
				for (int o=maxP; o>=0; o--) {
					if (pow(2, o) <= (nums[i]-curIdx)) {
						maxIdx = o;
						break;
					}
				}

				// merge all eligible As
				curans += abc[maxIdx];
				curIdx += pow(2,maxIdx);
			}
			ans.push_back(curans);
		}
		return ans;
	}
};
