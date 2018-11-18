/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
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
解题思路:进行中序遍历一遍，查看取出的数列是否是有序状态
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	vector<int> res;
    	travelBinaryTree(root, res);
    	int size = res.size();
    	for(int i = 0; i < size-1; i++){
    		if(res[i] >= res[i+1]){
    			return false;
    		}
    	}


    	return true;
    }

    void travelBinaryTree(TreeNode* root, vector<int>& res){
    	if(NULL != root){
    		travelBinaryTree(root->left, res);
    		res.push_back(root->val);
    		travelBinaryTree(root->right, res);
    	}
    }
};

/*
首先判断左子树上的节点值都小于根节点值，右子树上的节点值都大于根节点上的值，对整棵树上的节点依次进行如上验证。
注意节点为NULL时，为一颗有效的二叉搜索树
*/
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if ( !root ) return true;
		bool rel = checkl( root->left, root->val ), rer = checkr( root->right, root->val );
		return rel && rer && isValidBST( root->left ) && isValidBST( root->right );
	}
	bool checkl(TreeNode* root, int value) {
		if ( !root ) return true; 
		return root->val < value && checkl( root->left, value ) && checkl( root->right, value );
	}
	bool checkr(TreeNode* root, int value) {
		if ( !root ) return true; 
		return root->val > value && checkr( root->left, value ) && checkr( root->right, value );
	}
};