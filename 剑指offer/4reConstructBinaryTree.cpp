/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
	//首先确定根，然后根据根节点的位子对左右子树(和原问题是同一个问题，即子树的前序遍历和中序遍历序列)进行递归建树。
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() && vin.empty()) {
			return NULL;
		}
		int val_root = pre[0];
		int index_root = 0;
		for (int i = 0; i < vin.size(); i++) {
			if (val_root == vin[i]) {
				index_root = i;
				break;
			}
		}

		TreeNode* proot = new TreeNode(val_root);
		TreeNode* pleft = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + index_root + 1), vector<int>(vin.begin(), vin.begin() + index_root));
		TreeNode* pright = reConstructBinaryTree(vector<int>(pre.begin() + index_root + 1, pre.end()), vector<int>(vin.begin() + index_root + 1, vin.end()));
		proot->left =  pleft;
		proot->right = pright;
		return proot;
	}
};


/*TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0)
            return NULL;
        struct TreeNode Treenode=TreeNode(pre[0]);
        struct TreeNode* Tree=&Treenode;
        int i=0;
        for(;i<vin.size();i++){
            if(vin[i]==pre[0])
                break;
        }
        int left_len=i;
        vector<int> left_pre(pre.begin()+1,pre.begin()+1+left_len);
        vector<int> left_vin(vin.begin(),vin.begin()+left_len);
        Tree->left=reConstructBinaryTree(left_pre,left_vin);
		printf("%d",Tree->left->val);
        vector<int> right_pre(pre.begin()+1+left_len,pre.end());
        vector<int> right_vin(vin.begin()+left_len+1,vin.end());
        Tree->right=reConstructBinaryTree(right_pre,right_vin);
        return Tree;
    }*/