/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
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
解题思路： 这道题相当于是合并两个链表的延伸，当合并两个链表时要清楚返回的头结点是否是存在于堆栈段。可以new一个node，也可以直接使用两条链表当中的头结点。我的想法是在合并的过程中尽量不使用new过程来在堆栈段分配空间，直接对vector中的ListNode进行重新组成新的链表，这样内存空间就是由vector来自动进行管理。
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	int size = lists.size();
    	ListNode* pHead = NULL;
    	int i = 0;
    	for(i = 0; i < size; i++){
    		pHead = mergeTLists(pHead,lists[i]);
    	}
    	return pHead;
    }

    ListNode* mergeTLists(ListNode* list1, ListNode* list2){
    	if(NULL == list1){
    		return list2;
    	}

    	if(NULL == list2){
    		return list1;
    	}

    	ListNode *pHead = NULL;
    	if(list1->val < list2->val){
    		pHead = list1;
    		list1 = list1->next;
    	}else{
    		pHead = list2;
    		list2 = list2->next;
    	}

    	ListNode* ptmp = pHead;
    	while(NULL != list1 && NULL != list2){
    		if(list1->val < list2->val){
    			ptmp->next = list1;
    			ptmp = list1;
    			list1 = list1->next;
    		}else{
    			ptmp->next = list2;
    			ptmp = list2;
    			list2 = list2->next;
    		}
    	}

    	if(NULL != list1){
    		ptmp->next = list1;
    	}

    	if(NULL != list2){
    		ptmp->next = list2;
    	}

    	return pHead;
    }
};
