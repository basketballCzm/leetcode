/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//思路： 这里只需要考虑两个指针，pcur和pcur->next，如果两者相等则覆盖，如果两者不相等则向后偏移
class Solution {
  public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}

		ListNode* pcur = head;
		while (pcur) {
			while (pcur->next && pcur->val == pcur->next->val) {
				pcur->next = pcur->next->next;
			}
			pcur = pcur->next;
		}

		return head;
	}
};