//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
  public:
    //二叉树的层次遍历使用队列
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;

        if (NULL == root) {
            return res;
        }

        //尾进头出
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* ptmp = que.front();
            que.pop();
            if (NULL != ptmp) {
                res.push_back(ptmp->val);
                que.push(ptmp->left);
                que.push(ptmp->right);
            }
        }

        return res;
    }
};