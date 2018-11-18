/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
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
解题思路: 
这是遍历一遍：递归直到最后一个节点，回溯的时候计数，NULL的时候计数为-1，最后一个节点计数为0, 倒数第二个节点计数为1
遍历两遍： 首先计算整个链表的节点数目，然后算出当前要删除节点的位置，最后遍历，记录要删除节点的前一个节点进行删除操作。
*/
class Solution {
public:
	// n 一定是有效的
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(NULL == head){
    		return head;
    	}
    	int index = 0;
    	bool flag = false;
    	deleteNthFromEnd(head, n, index, flag);
    	if(!flag){
    		head = head->next;
    	}
    	return head;
    }

    void deleteNthFromEnd(ListNode* head, int n, int& index, bool& flag){
    	if(NULL == head){
    		index = -1;
    		return; 
    	}

    	deleteNthFromEnd(head->next, n, index, flag);
    	index++;
    	if(n == index){
    		head->next = head->next->next;
    		flag = true;
    	}
    }
};