/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
1. 找到第一个大于目标元素的前一个元素
2. 将值小的元素单独取出来组成一个链表，然后将大于的元素接在该链表的后面。
*/
class Solution {
  public:
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* pnew = new ListNode(0);
		pnew->next = head;
		ListNode* pre = pnew;
		while (pre->next && pre->next->val < x) {
			pre = pre->next;
		}

		ListNode* pcur = pre;
		while (pcur) {
			if (pcur->next && pcur->next->val < x) {
				ListNode* tmp = pcur->next;
				pcur->next = pcur->next->next;
				tmp->next = pre->next;
				pre->next = tmp;
				//保持移动元素的相对顺序
				pre = pre->next;
				continue;
			}

			pcur = pcur->next;
		}
	}
};

//方法2 使用两个链表，新建一个链表将原链表小于目标值的元素接在该链表的后面，最后把处理完成的原链表直接接在新链表的后面
class Solution {
  public:
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) {
			return head;
		}

		ListNode* pnew = new ListNode(0);
		ListNode* pre = pnew;

		ListNode* pnew1 = new ListNode(0);
		pnew1->next = head;
		ListNode* ptmp = pnew1;
		//要删除元素用前面一个元素进行循环
		while (ptmp) {
			if (ptmp->next && ptmp->next->val < x) {
				ListNode* ptmp1 = ptmp->next;
				ptmp->next = ptmp->next->next;
				ptmp1->next = pre->next;
				pre->next = ptmp1;
				//使用尾插法，保持相对位置
				pre = pre->next;
				continue;
			}
			ptmp = ptmp->next;
		}
		pre->next = pnew1->next;
		return pnew->next;
	}
};

