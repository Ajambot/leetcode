// IDEA: for each key, store a vector of timestamps. Then when we are looking for a value at a timestamp,
// we find the highest timestamp in the vector that's less than or equal to the query using binary search.
//
// We do not need to sort on every insertion since the timestamps are strictly increasing, so we can
// just append at the end and it will continue to be sorted. 
class TimeMap {
public:
	unordered_map<string, vector<pair<int, string>>> tmap;
	TimeMap() {
	}

	void set(string key, string value, int timestamp) {
		if (!tmap.count(key))
			tmap[key] = vector<pair<int,string>>();
		tmap[key].push_back({timestamp, value});
	}

	string get(string key, int timestamp) {
		// edge case where the key doesn't exist
		if (!tmap.count(key))
			return "";
		return binSearch(tmap[key], timestamp);
	}

	string binSearch(vector<pair<int, string>>& ts, int q) {
		int l = 0, r = ts.size()-1;
		while (l < r) {
			// + 1 so it's not stuck on an infinite loop
			int m = (l+r+1)/2;
			if (q < ts[m].first) {
				r = m-1;
			} else {
				l = m;
			}
		}
		// edge case where there is no timestamp less than or equal to q
		return ts[l].first <= q? ts[l].second : "";
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
