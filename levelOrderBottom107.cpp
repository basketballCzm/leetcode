/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(NULL == root){
            return res;
        }
        deque<TreeNode*> que;
        que.push_back(root);
        while(!que.empty()){
            int len = que.size();
            vector<int> v;
            while(len--){
                TreeNode* ptmp = que.front();
                que.pop_front();
                v.push_back(ptmp->val);
                if(NULL != ptmp->left){
                    que.push_back(ptmp->left);
                }

                if(NULL != ptmp->right){
                    que.push_back(ptmp->right);
                }
            }

            res.insert(res.begin(), v);
        }

        return res;
    }
};