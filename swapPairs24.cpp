/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
思路: 思路和删除链表中的一个节点类似，要注意在置换节点过程中next指针变化的顺序，注意不要使用值变化后的指针。对于头结点的情况也要单独考虑
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(NULL == head || NULL == head->next){
    		return head;
    	}
    	ListNode* pcur = head;
    	ListNode* plast = NULL;
    	ListNode* PTemp = NULL;
    	//使用哨兵节点可以避免校验头结点的情况
    	while(NULL != pcur && NULL != pcur->next){
    		if(pcur == head){
    			//一冲  二穿  三回
    			head = pcur->next;
    			pcur->next = pcur->next->next;
    			head->next = pcur; 
    			plast = pcur;
    			pcur = pcur->next;
    			continue;
    		}

    		//注意这里画图
    		plast->next = pcur->next;
    		pcur->next = pcur->next->next;
    		plast->next->next = pcur;
    		plast = pcur;
    		pcur = pcur->next;
    	}

    	return head;
    }
};