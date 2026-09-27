// IDEA: Keep 2 heaps. MaxH keeps the left half of the sorted list of nums, MinH keeps the right half.
// The median is going to be either the max of the left half, the min of the right half, or the avg of
// both. 
//
// We insert in the left half when the element is less than the top of the maxH, and in the right when
// it's bigger than the top of the minH.
//
// We have to rebalance the heap if the difference in sizes between both heaps is bigger than 1 to keep
// the median property in the heaps. 
class MedianFinder {
public:
	priority_queue<int> maxH, minH; 

	MedianFinder() {
	}

	void addNum(int num) {
		if (maxH.empty())
			maxH.push(num);
		// insert in left half
		else if (num < maxH.top())
			maxH.push(num);
		else if (minH.empty())
			minH.push(-num);
		// insert in right half
		else if (num > -minH.top())
			minH.push(-num);

		// insert in left half by default
		else
			maxH.push(num);

		// rebalance the heap
		if (abs((int)maxH.size() - (int)minH.size()) > 1) {
			if (maxH.size() > minH.size()) {
				minH.push(-maxH.top());
				maxH.pop();
			} else {
				maxH.push(-minH.top());
				minH.pop();
			}
		}
	}

	double findMedian() {
		// median in left half
		if (maxH.size() > minH.size()) {
			return maxH.top();
		// median in right half
		} else if (minH.size() > maxH.size()) {
			return -minH.top();
		// median in the middle
		} else {
			return (-minH.top() + maxH.top())/2.0;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
