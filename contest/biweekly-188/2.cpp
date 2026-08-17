class Solution {
public:
    int maximumWidth(vector<int>& planks) {
		long long maxWidth = 1;
		unordered_map<long long, long long> hp;
		vector<unordered_set<int>> used(planks.size(), unordered_set<int>());
		// O(n^2)
		for (int i=0; i<planks.size(); i++) {
			if (hp.count(planks[i]) == 0)
				hp[planks[i]] = 0;
			maxWidth = max(maxWidth, ++hp[planks[i]]);
			for (int o = i+1; o<planks.size(); o++) {
				long long mrgPlnk = planks[i] + planks[o];
				if (used[i].count(planks[o]) || used[o].count(planks[i]))
					continue;
				if (hp.count(mrgPlnk) == 0) { 
					hp[mrgPlnk] = 0;
				}
				maxWidth = max(maxWidth, ++hp[mrgPlnk]);
				used[i].insert(planks[o]);
				used[o].insert(planks[i]);
			}
		}

		return maxWidth;
    }
};
