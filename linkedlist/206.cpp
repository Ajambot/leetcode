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
class Solution {
public:
	// Iterative solution. Order of operations is very important to not lose reference to rest of ll
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head, *prev = nullptr;

		while (cur != nullptr) {
			// Use tmp to not lose reference of rest of ll
			ListNode* tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
	}

	// Recursive solution
	// You need a double pointer to modify the address of the pointer within a function. Otherwise, the address is just passed as value.
	ListNode* reverseListRecursive(ListNode** head, ListNode* cur) {
		// Base case
		if (cur == nullptr || cur->next == nullptr) {
			*head = cur;
			return cur;
		}
		
		// recurrence relation
		reverseListRecursive(head, cur->next)->next = cur;
		cur->next = nullptr;
		return cur;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		reverseListRecursive(&head, cur);
		return head;
	}
};
