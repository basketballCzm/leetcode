/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
1. 头插法
2. 递归法
*/

class Solution {
  public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}

		ListNode* pnew = new ListNode(0);
		pnew->next = head;

		ListNode* pcur = pnew->next;
		while (pcur->next) {
			ListNode* ptmp = pcur->next;
			pcur->next = pcur->next->next;
			ptmp->next = pnew->next;
			pnew->next = ptmp;
		}

		return pnew->next;
	}
};

class Solution {
  public:
	ListNode* reverseList(ListNode* head) {
		//为空或者最后一个元素也就没有必要进行翻转链表,结束时返回尾部的头结点
		if (!head || !head->next) {
			return head;
		}
		ListNode* t = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return t;
	}
};



//这种写法比较有趣
class Solution {
  public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* t = reverseList(head->next);
		//将head连到尾部
		head->next->next = head;
		head->next = NULL;
		return t;
	}
};