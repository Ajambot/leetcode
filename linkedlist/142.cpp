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
	// Continuing with the explanation from linkedlist/141.cpp:
	// - The fast pointer is also getting a net +1 away from the slow pointer.
	// - Consider there is some section of the linked list that does not contain a loop
	// and some section that does contain a loop. 
	// - Let's say the section that doesn't contain a loop has x nodes and the section that
	//   DOES contain a loop has y nodes. 
	// - It will take the slow pointer x steps to get from the beginning of the linked list
	//   to the beginning of the loop. At which point, the slow pointer will be x nodes away
	//   from the fast pointer (i.e. the beginning of the loop.) since their distance has 
	//   increased by a net 1 for x iterations.
	// - This also means there are (y-x) nodes between the fast pointer and the begginning of the loop.
	// - Since the distance between the fast pointer and the slow pointer is decreasing by a net 1 on
	//   each iteration, both pointers will meet after (y-x) steps (i.e. (y-x) nodes away from the 
	//   beginning of the loop.)
	// - This means that when they meet, they will be exactly x steps away from the beginning of the loop
	// - Since there are also, x nodes between the beginning of the linked list and the beginning of the loop
	//   we can start a 2nd slow pointer from the beginning of the linked list and walk them both forward by 1 step
	//   each time.
	// - After x steps, both slow pointers will meet at the beginning of the loop. We can return the node they meet
	//   at because that will be the beginning of the loop.
	ListNode *detectCycle(ListNode *head) {
		if (!head) {
			return NULL;
		}
		ListNode* slow = head, *fast = head;

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				ListNode* cur = head;
				while (cur != slow) {
					slow = slow->next;
					cur = cur->next;
				}
				return cur;
			}
		}
		return NULL;
	}
};
