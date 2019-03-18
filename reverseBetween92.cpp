/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 思路: 首要找到翻转头的前一个元素，然后依次对翻转元素使用头插法
 */
class Solution {
  public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* pnew = new ListNode(0);
		pnew->next = head;
		ListNode* pre = pnew;
		for (int i = 0; i < m - 1; i++) {
			pre = pre->next;
		}

		//头插法这里当前元素是空头部后面一位
		ListNode* pcur = pre->next;
		int cnt = n - m;
		while (cnt--) {
			if (pcur->next) {
				ListNode* ptmp = pcur->next;
				pcur->next = pcur->next->next;
				//pcur = pcur->next;
				ptmp->next = pre->next;
				pre->next = ptmp;
			}
		}

		return pnew->next;
	}
};