/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
解题思路: 由于这题是将链表转化为高度平衡的二叉搜索树，由于链表只能单向遍历的特点，可以将链表先转化成一个vector,
然后对vector进行构造树，主要的思路是每次取中间值当做根节点，然后构造左子树，然后构造右子树。注意构造树结束条件
*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	vector<int> res;
    	listToVector(head, res);

    	int size = res.size();
    	return constructionTree(res, 0, size-1);
    }

    TreeNode* constructionTree(vector<int> &res, int left, int right){
    	if(left > right){
    		return NULL;
    	}
    	int mid = (left+right)/2;

    	TreeNode *head = new TreeNode(res[mid]);
    	head->left = constructionTree(res, left, mid-1);
    	head->right = constructionTree(res,mid+1,right);

    	return head;
    	
    }

    void listToVector(ListNode* head, vector<int>& res){
    	while(NULL != head){
    		res.push_back(head->val);
    		head = head->next;
    	}
    }
};
