class Solution {
public:
	long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
		sort(boosts.begin(), boosts.end(), [](const auto& a, const auto& b) {
			return a[1] > b[1];
		});

		long long minStrength = 0;
		// { next index to remove, boost }
		priority_queue<pair<long long, long long>> pq;
		long long curBoost = 0;
		long long boostIdx = 0;
		bool cantBeat = false;
		for (int i=monsters.size()-1; i>=0; i--) {
			// cout << boosts[boostIdx][0] << " " << boosts[boostIdx][1] << " " << boosts[boostidx][2] << endl;
			while (boostIdx < boosts.size() && boosts[boostIdx][0] <= i && i <= boosts[boostIdx][1]) {
				pq.push({boosts[boostIdx][0]-1, boosts[boostIdx][2]});
				curBoost += boosts[boostIdx][2];
				boostIdx++;
			}

			while (!pq.empty() && pq.top().first == i) {
				curBoost -= pq.top().second;
				pq.pop();
			}


			cout << curBoost << endl;
			if (cantBeat) {
				minStrength += monsters[i];
			}
			else if (monsters[i]-curBoost > 0) {
				cantBeat = true;
				minStrength += monsters[i]-curBoost;
			}
		}
		return minStrength;
	}
};
