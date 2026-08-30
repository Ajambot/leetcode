class Solution {
public:
	// IDEA: Always 3 possible solutions: 
	// 1. -1 if the bishop is not on a tile with the same color
	// as the target. We can check this because the sum of the coordinates of white tiles are even and 
	// black tiles are odd. 
	//
	// 2. 1 if the target sits in one of the 4 diagonals of the bishop. We check this by checking that
	// x distance and the y distance are the same.
	//
	// 3. 2 if the target does not sit in one of the 4 diagonals.
	//
	// The bishop can always reach a target in 2 moves or less (if it sits on the same colored tile)
	int minBishopMoves(vector<int>& source, vector<int>& target) {
		int sourceSum = source[0] + source[1];
		int targetSum = target[0] + target[1];
		if ((sourceSum%2==0 && targetSum%2!=0) || (sourceSum%2!=0 && targetSum%2==0)) {
			return -1;
		}

		int diffX = abs(source[0]-target[0]), diffY = abs(source[1]-target[1]);
		return (diffX==diffY)? 1: 2;
	}
};
