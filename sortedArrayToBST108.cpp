/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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
class Solution {
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return BST(nums, 0, nums.size() - 1);
    }

    TreeNode* BST(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int len = (start + end) / 2;
        TreeNode* proot = new TreeNode(nums[len]);
        TreeNode* pleft = BST(nums, start, len - 1);
        TreeNode* pright = BST(nums, len + 1, end);
        proot->left = pleft;
        proot->right = pright;

        return proot;

    }
};