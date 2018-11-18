/*
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
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
思路:中序遍历，首先检查左子树是否相等，检查树根节点相等，检查右子树相等，如果三者都是正确的，则返回true。
    对递归的书写要有整体思想，分治的整体思想
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	return travelBinaryTree(p, q);
    }

    bool travelBinaryTree(TreeNode *p, TreeNode *q){
    	bool bleft = false;
    	bool bright = false;
    	if(NULL != p && NULL != q){
    		bleft = travelBinaryTree(p->left,q->left);
    		
    		if(p->val != q ->val){
    			return false;
    		}
    		bright = travelBinaryTree(p->right,q->right);
    		
    	}else if(NULL == p && NULL == q){
    		return true;
    	}else{
    		return false;
    	}

    	return bleft&bright;
    }
};