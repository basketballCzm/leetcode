/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/
/*
思路:这道题开始的时候想复杂了，可以直接使用层次遍历，注意层次遍历使用对列来实现，然后再对奇数层的元素进行翻转，再存入vector<vector<int>>中，注意使用层次遍历时记录跨行的标识。
    后面也可以想象区分左右节点的次序来解题。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (NULL == root) {
            return res;
        }

        deque<TreeNode*> deq;
        bool flag = false;
        deq.push_back(root);
        while (!deq.empty()) {
            int len = deq.size();
            vector<int> v;
            while (len--) {
                TreeNode* ptmp = deq.front();
                deq.pop_front();
                v.push_back(ptmp->val);
                if (NULL != ptmp->left) {
                    deq.push_back(ptmp->left);
                }
                if (NULL != ptmp->right) {
                    deq.push_back(ptmp->right);
                }
            }
            if (flag) {
                /*翻转容器的两种方法
                1. 使用reverse_iterator迭代器
                2. 使用algorithm库函数reserve
                */
                reserve(v.begin(), v.end());
            }
            flag = !flag;
            res.push_back(v);
        }

        return res;
    }
};