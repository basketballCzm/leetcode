/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
/*
思路：
1. 复制每个节点，并且将每个复制节点添加到当前节点后面
2. 改变每个复制节点的random域 AA->random = A->random->next
3. 拆分复制节点和原节点
*/
class Solution {
  public:
	RandomListNode* Clone(RandomListNode* pHead) {
		if (NULL == pHead) {
			return NULL;
		}
		RandomListNode* ptmp = pHead;
		while (NULL != ptmp) {
			RandomListNode* pnew = new RandomListNode(ptmp->label);
			pnew->next = ptmp->next;
			ptmp->next = pnew;
			ptmp = pnew->next;
		}

		ptmp = pHead;
		while (NULL != ptmp && NULL != ptmp->next) {
			//校验random指针是否为NULL
			if (NULL != ptmp->random) {
				ptmp->next->random = ptmp->random->next;
			}
			ptmp = ptmp->next->next;
		}

		ptmp = pHead;
		RandomListNode* ppHead = pHead->next;
		RandomListNode* pptmp = ppHead;
		while (NULL != ptmp && NULL != ptmp->next && NULL != pptmp) {
			ptmp->next = ptmp->next->next;
			if (NULL != pptmp->next) {
				pptmp->next = pptmp->next->next;
			}

			ptmp = ptmp->next;
			pptmp = pptmp->next;
		}


		/*这样的拆分代码没见过
		RandomListNode *pCloneHead = pHead->next;
		RandomListNode *tmp;
		currNode = pHead;
		while(currNode->next){
		    tmp = currNode->next;
		    currNode->next =tmp->next;
		    currNode = tmp;
		}
		*/

		return ppHead;
	}
};