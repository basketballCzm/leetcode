/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 思路：使用3个指针，前驱，当前，后继。注意要new一个空的头结点
 */
class Solution {
  public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (NULL == head || NULL == head->next) {
			return head;
		}
		ListNode* phead = new ListNode(0);
		phead->next = head;
		ListNode* pre = phead;
		/*		ListNode* pcur = head;
				ListNode* plast = head->next;
				while (NULL != pcur) {
					while (NULL != plast && pcur->val == plast->val) {
						plast = plast->next;
					}
					if (pcur->next != plast) {
						pre->next = plast;
						pcur = plast;
					} else {
						pre = pcur;
						pcur = plast;
					}

					if (NULL != plast) {
						plast = plast->next;
					}
				}*/
		while (pre->next) {
			ListNode* pcur = pre->next;
			while (pcur->next && pcur->next->val = pcur->val) {
				pcur = pcur->next;
			}
			if (pre->next != pcur) {
				//这种情况不需要改变pre的值
				pre->next = pcur->next;
			} else {
				pre = pre->next;
			}
		}

		return phead->next;
	}
};









//思路: 这种写法要注意，同样是一样的方法。这种写法没有维护pcur和plast指针，导致代码逻辑简单了很多
class Solution {
  public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;
		while (pre->next) {
			ListNode *cur = pre->next;
			while (cur->next && cur->next->val == cur->val) {
				cur = cur->next;
			}
			if (cur != pre->next) pre->next = cur->next;
			else pre = pre->next;
		}
		return dummy->next;
	}
};