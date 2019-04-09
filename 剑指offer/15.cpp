//输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
//回溯法  快慢指针法
class Solution {
  public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* pNode = NULL;
        unsigned int step;
        FindR(pListHead, pNode, k, step);
        return pNode;
    }

    void FindR(ListNode* pListHead, ListNode*& pNode , unsigned int k, unsigned int& step) {
        if (NULL == pListHead) {
            step = 0;
            return;
        } else {
            FindR(pListHead->next, pNode, k, step);
            step++;
            if (k == step) {
                pNode = pListHead;
            }
        }
    }
};

//快慢指针法
class Solution {
  public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //快慢指针法
        ListNode* pslow = pListHead;
        ListNode* pfast = pListHead;
        //快指针移动k-1位到达第k位
        for (int i = 0; i < k - 1 && NULL != pfast; i++, pfast = pfast->next);
        //校验溢出位
        if (NULL == pfast) {
            return NULL;
        }
        while (NULL != pfast->next) {
            pfast = pfast->next;
            pslow = pslow->next;
        }
        return pslow;
    }
};
