/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

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
解题思路: 将每K个节点的子链表进行翻转，然后将各个子链表连接起来形成总链表。
注意事项:
1. 使用哨兵节点，避免分类讨论。
2. 对K个节点进行就地翻转，需要保存K个节点的首节点和该K个节点之前的K个节点中的最后一个节点
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(NULL == head || 0 == k || 1 == k){
    		return head;
    	}

    	ListNode *phead = new ListNode(0);
    	ListNode *pTemp = head;
    	ListNode *pcur = head;
    	ListNode *plast = phead;
    	phead->next = head;
    	int cnt = 0;
    	while(NULL != pTemp){
    		cnt++;
    		pTemp = pTemp->next;
    	}

    	pTemp = head;
    	for(int i = 0; i < cnt/k; i++){
    		pTemp = pTemp->next;
    		for(int j = 0; j < k-1; j++){
    			//删除节点
    			pcur->next = pTemp->next;
    			//插入节点
    			pTemp->next = plast->next;
    			plast->next = pTemp;
    			//向下循环
    			pTemp = pcur->next;
    		}
    		plast = pcur;
    		pcur = pTemp;
    	}

    	return phead->next;
    }
};


//改进下从头结点开始翻转
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	//没有或者只有一个元素
    	if(NULL == head || NULL == head->next){
    		return head;
    	}

    	ListNode *phead = new ListNode(0);
    	phead->next = head;
    	//从第二个节点开始循环
    	ListNode *pTemp = head->next;
    	//回执最后为NULL
    	head->next = NULL;
    	ListNode *pNew = NULL;
    	while(NULL != pTemp){
    	 	pNew = pTemp->next;
    		pTemp->next = phead->next;
    		phead->next = pTemp;
    		pTemp = pNew;
    	}

    	return phead->next;

    }
};

//从头结点开始翻转
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	//没有或者只有一个元素
    	if(NULL == head || NULL == head->next){
    		return head;
    	}

    	ListNode *phead = new ListNode(0);
    	ListNode *p = NULL;
    	phead->next = NULL;

    	while(NULL != head){
    		p = head->next;
    		head->next = phead->next;
    		phead->next = head;
    		head = p;
    	}

    	return phead->next;

    }
};