class Solution {
public:
	int maxValidSplits(vector<int>& nums) {
		int maxScore = 0;
		int curScore = 0;
		for (int o=0; o<nums.size(); o++) {
			vector<int> s1 = sliceVector(nums, 0, o+1);
			vector<int> s2 = sliceVector(nums, o+1, nums.size());
			if (findGCD(s1) == findGCD(s2))
				curScore++;
		}
		maxScore = max(maxScore, curScore);
		for (int i = 0; i<nums.size(); i++) {
			vector<int> curSlice = removeOne(nums, i);
			curScore = 0;
			for (int o=0; o<curSlice.size(); o++) {
				vector<int> s1 = sliceVector(curSlice, 0, o+1);
				vector<int> s2 = sliceVector(curSlice, o+1, curSlice.size());
				if (findGCD(s1) == findGCD(s2))
					curScore++;
			}
			maxScore = max(maxScore, curScore);
		}
		return maxScore;
	}

	vector<int> sliceVector(vector<int>& nums, int begin, int end) {
		return vector<int>(nums.begin()+begin, nums.begin()+end);
	} 

	vector<int> removeOne(vector<int>& nums, int idx) {
		vector<int> newVector;
		for (int i=0; i<nums.size(); i++) {
			if (i==idx)
				continue;
			newVector.push_back(nums[i]);
		}
		return newVector;
	}

	int findGCD(const vector<int>& nums) {
		if (nums.empty()) return 0;

		return accumulate(nums.begin() + 1, nums.end(), nums[0], [](int a, int b) {
			return gcd(a, b);
		});
	}
};

