/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
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
思路: 主要是根据链表长度和向右循环的长度来查找中间的截断点，然后将阶段点之后的部分插入到链表头，置截断点之后的指针为空。
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(NULL == head || NULL == head->next || 0 == k){
            return head;
        }
        ListNode *ptmp = head;
        int size = 0;
        while(NULL != ptmp){
            size++;
            ptmp = ptmp->next;
        }

        //去除循环
        k = k%size;
        if(0 != k){
            //截取位置
            k = size-k;
            ptmp = head;
            //循环次数
            for(int i = 0; i < k-1; i++){
                ptmp = ptmp->next;
            }

            //尾节点
            ListNode* pend = ptmp;
            while(NULL != pend->next){
                pend = pend->next;
            }

            //核心语句
            pend->next = head;
            head = ptmp->next;
            ptmp->next = NULL;
        }

        return head;
    }
};