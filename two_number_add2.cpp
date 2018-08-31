/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//对于特别大的数字不能通过测试，由于类型范围的限制
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	unsigned long long num1 = get_num(l1);
    	unsigned long long num2 = get_num(l2);
    	unsigned long long num3 = num1+num2;
    	ListNode* l3 = NULL;
    	ListNode *pTemp = NULL;
    	ListNode *pNew = NULL;
    	if(0 == num3){
    		pNew = new ListNode(0);
    		l3 = pNew;
    		return l3;
    	}
    	while(num3){
    		int n = num3%10;
    		num3 = num3/10;
    		pNew = new ListNode(n);
            if(NULL == l3){
                l3 = pNew;
                continue;
            }
            pTemp = l3;
    		while(NULL != pTemp->next){
    			pTemp = pTemp->next;
    		}
    		pTemp->next = pNew;
    	}
    	return l3;
    }

    unsigned long long get_num(ListNode* l){
    	unsigned long long cnt = 1;
    	unsigned long long sum = 0;
    	ListNode* pTemp = l;
    	while(NULL != pTemp){
    		sum += (pTemp->val)*cnt;
    		cnt *= 10;
    		pTemp = pTemp->next;
    	}
    	return sum;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *p1 = l1;
    	ListNode *p2 = l2;
    	ListNode *l3 = NULL;
    	//该指针指向最后一个节点，每次尾部插入不需要遍历
    	ListNode *pLast = NULL;
    	int sum = 0;
    	int flag = 0;
    	while(NULL != p1 && NULL != p2){
    		sum = p1->val + p2->val + flag;
    		flag = 0;
    		if(sum >= 10){
    			sum = sum%10;
    			flag = 1;
    		}
    		ListNode *pNew = new ListNode(sum);
    		if(NULL == l3){
    			l3 = pNew;
    			pLast = pNew;
    			//continue 之前要next
    			p1 = p1->next;
    			p2 = p2->next;
    			continue;
    		}
    		pLast->next = pNew;
    		pLast = pNew;
    		p1 = p1->next;
    		p2 = p2->next;
    	}


    	while(NULL != p1){
    		sum = p1->val + flag;
    		flag = 0;
    		if(sum >= 10){
    			sum = sum % 10;
    			flag = 1;
    		}
    		ListNode *pNew = new ListNode(sum);
    		pLast->next = pNew;
    		pLast = pNew;
    		p1 = p1->next;
    	}

    	while(NULL != p2){
    		sum = p2->val + flag;
    		flag = 0;
    		//mark 进1 尾9 任进1
    		if(sum >= 10){
    			sum = sum % 10;
    			flag = 1;
    		}
    		ListNode *pNew = new ListNode(sum);
    		pLast->next = pNew;
    		pLast = pNew;
    		p2 = p2->next;
    	}

    	if(NULL == p1 && NULL == p2 && flag){
    		ListNode *pNew = new ListNode(1);
    		pLast->next = pNew;
    		pLast = pNew;
    	}

    	return l3;
    }
};



int main(){
	Solution s;
	ListNode *l1 = new ListNode(1);
	for(int i = 0; i < 9; i++){
		ListNode *pNew = new ListNode(9);
		ListNode *pTemp = l1;
		while(NULL != pTemp->next){
			pTemp = pTemp->next;
		}
		pTemp->next = pNew;
	}
	std::cout << s.get_num(l1) <<std::endl;;
}