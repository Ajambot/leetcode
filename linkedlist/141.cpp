/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// We use a fast and a slow pointer to traverse the linked list
	// The fast pointer moves forward 2 nodes, the slow one moves forward 1.
	// If there are no cycles in the list, the fast pointer reaches the end before
	// the slow pointer and we return false.
	// If there ARE cycles in the list, now the fast pointer is eventually going to
	// catch up to the slow pointer.
	// We can prove this in the following way:
	//	- Once both nodes are inside the cycle, the fast pointer will be x nodes
	//	  away from the slow pointer
	//	- On every loop iteration, the fast pointer is getting 2 nodes closer to
	//	  the slow pointer, while the slow pointer is getting 1 node away from the
	//	  fast pointer
	//	- This means that the distance x between fast and slow is increasing by 1
	//	  and decreasing by 2 every iteration. This is a net -1 to the distance 
	//	  between slow and fast.
	//	- That means after x turns, fast will catch up to slow and they will be 
	//	  at the same node exactly. If so, there is a loop.
	bool hasCycle(ListNode *head) {
		if (!head) {
			return false;
		}
		ListNode* slow = head, *fast = head;

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};
