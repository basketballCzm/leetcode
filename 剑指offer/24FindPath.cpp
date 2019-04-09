/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/
class Solution {
  public:
    //深度优先遍历
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int>> res;
        vector<int> sigres;
        if (NULL == root) {
            return res;
        }
        FindPathR(root, expectNumber, res, sigres);
        return res;
    }

    void FindPathR(TreeNode* root, int target, vector<vector<int>>& res, vector<int> sigres) {
        if (NULL == root) {
            int sum = 0;
            for (auto x : sigres) {
                sum += x;
            }
            if (target == sum) {
                res.push_back(sigres);
            }
        } else {
            sigres.push_back(root->val);
            if (NULL == root->left && NULL == root->right) {
                FindPathR(root->left, target, res, sigres);
                return;
            }
            FindPathR(root->left, target, res, sigres);
            FindPathR(root->right, target, res, sigres);
        }
    }
};