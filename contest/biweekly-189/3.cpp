class Solution {
public:
    int kthDigit(long long k) {
	if (k < 10) return k;
	k-=10;
	int numOfNums = 90;
	int numDigits = 2;
	while (k >= numOfNums) {
	    k -= numOfNums;
	    numDigits += 1;
	    numOfNums *= 10;
	}

	int numOfNumsInSlot = 10*(numDigits);
	int slotNumber = k/numOfNumsInSlot;
	int l = numDigits * 10 + 10 * slotNumber; 
	int r = l + 9;
	k = k % numOfNumsInSlot;
	vector<int> slot;
	for (int i = l; i<=r; i++) {
	    slot.push_back(i);
	}

	if (slotNumber%2==0) {
	    sort(slot.begin(), slot.end(), greater<int>());
	}

	string desiredNumber = to_string(slot[k/numDigits]);
	int desiredDigit = desiredNumber[k%numDigits] - '0';
	return desiredDigit;
    }
};
