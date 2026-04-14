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

	// Iterate over both lists, picking the least of the two current nodes to append
	// to the merged list.
	// 3 cases to worry about:
	//	1. One list is empty at the beginning:
	//		Return the other list, which is already sorted.
	//	2. Both lists still have elements left:
	//		Append the head with the lesser value. Then move the
	//		current pointer of that list forward.
	//	3. We run out of one of the lists while the other still has
	//	elements:
	//		Append the rest of the elements at the end of the merged list.
	//		They should all be greater than the current tail.
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// Case 1.
		if (!list1)
			return list2;
		if (!list2)
			return list1;

		ListNode* head, *ptr1 = list1, *ptr2 = list2;

		if(list1->val < list2->val) {
			head = list1;
			ptr1 = ptr1->next;
		} else {
			head = list2;
			ptr2 = ptr2->next;
		}
		head->next = NULL;

		ListNode* cur = head;

		// Case 2.
		while (ptr1 && ptr2) {
			if (ptr1->val < ptr2->val) {
				cur->next = ptr1;
				ptr1 = ptr1->next;
				cur = cur->next;
				cur->next = NULL; // disconnect the merged list from the list we added from
			} else {
				cur->next = ptr2;
				ptr2 = ptr2->next;
				cur = cur->next;
				cur->next = NULL;
			}
		}

		// Case 3.
		if (ptr1) {
			cur->next = ptr1;
		} else if (ptr2) {
			cur->next = ptr2;
		}

		return head;
	}
};
