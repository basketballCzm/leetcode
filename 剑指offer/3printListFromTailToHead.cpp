/*
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
  public:
	//递归回溯时进行添加
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if (NULL == head) {
			return res;
		}

		printList(res, head);
		return res;
	}

	void printList(vector<int>& res, ListNode* head) {
		if (NULL == head) {
			return;
		}
		printList(res, head->next);
		res.push_back(head->val);
	}
};