/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// IDEA: Use fast and slow pointers. Fast will reach the end of 
// the list in half the time as slow. So slow will be at the middle
// of the list when fast is done.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
		ListNode* fast = head, *slow =head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
    }
};
