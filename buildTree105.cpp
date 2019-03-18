/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

/*
思路: 通过前序序列找到根节点，利用根节点使用中序序列划分左右子树的数目，再得到前序序列左右子树的数目。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() && inorder.empty()){
            return NULL;
        }

        return buildTreeR(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

    }

    TreeNode* buildTreeR(vector<int>& preorder, int pres, int pree, vector<int>& inorder, int ins, int ine){
        if(pres > pree || ins > ine){
            return NULL;
        }

        int rootval = preorder[pres];
        int index = 0;
        for(int i = ins; i <= ine; i++){
            if(inorder[i] == rootval){
                index = i;
                break;
            }
        }
        TreeNode* proot = new TreeNode(rootval);
        TreeNode* pleft = buildTreeR(preorder, pres+1, pres+(index-ins), inorder, ins, index-1);
        TreeNode* pright = buildTreeR(preorder, pres+(index-ins)+1, pree, inorder, index+1, ine);
        proot->left = pleft;
        proot->right = pright;

        return proot;
    }
};