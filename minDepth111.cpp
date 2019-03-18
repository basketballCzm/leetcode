/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
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
    int minDepth(TreeNode* root) {
        if(NULL == root){
            return 0;
        }

        int mindep = INT_MAX;
        minDepthR(root, 1, mindep);
        return mindep;
    }

    void minDepthR(TreeNode* root, int depth, int& mindep){
        if(NULL == root->left && NULL == root->right){
            if(mindep > depth){
                mindep = depth;
            }
        }
        if(NULL != root->left){
            minDepthR(root->left, depth+1, mindep);
        }

        if(NULL != root->right){
            minDepthR(root->right, depth+1, mindep);
        }
    }
};