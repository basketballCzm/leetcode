/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/
/*
解题思路：使用队列进行层次遍历，但是在记录跨层变换时需要扩充容器vector，在这里我构造了一个结构体来记录该节点所在树中的层次。
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
    struct nodeLevelFlag{
        //形参和成员变量不能写成一样
        nodeLevelFlag(TreeNode* node1, int level1){
            node = node1;
            level = level1;
        }
        TreeNode* node;
        int       level;
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(NULL == root){
            return res;
        }
        nodeLevelFlag rootLevelFlag(root,0);
        //stl默认为浅拷贝，如果要进行深拷贝需要自己写拷贝构造函数
        deque<nodeLevelFlag> deq;
        deq.push_back(rootLevelFlag);
        int level = -1;

        while(!deq.empty()){
            //现在在队列中的元素个数就是树的一层的个数
            nodeLevelFlag nodeflag = deq.front();
            if(level != nodeflag.level){
                res.push_back(vector<int>());
                level = nodeflag.level;
            }
            res[nodeflag.level].push_back(nodeflag.node->val);
            deq.pop_front();
            if(NULL != nodeflag.node->left){
                nodeLevelFlag leftLevelFlag(nodeflag.node->left, nodeflag.level+1);
                deq.push_back(leftLevelFlag);
            }

            if(NULL != nodeflag.node->right){
                nodeLevelFlag rightLevelFlag(nodeflag.node->right, nodeflag.level+1);
                deq.push_back(rightLevelFlag);
            }
        }

        return res;

    }
};