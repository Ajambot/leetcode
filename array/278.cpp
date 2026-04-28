// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// We use binary search to look for the first instance of a bad version.
// If our middle element is bad, then all version after it will be also bad
// and they will not be the first bad version.
//
// If our middle element is good, then the first bad version is going to be
// somewhere in [mid+1, r]
class Solution {
public:
	int firstBadVersion(int n) {
		int l = 1, r = n;
		while (l < r) {
			int mid = l+((r-l)/2);
			if (isBadVersion(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};
